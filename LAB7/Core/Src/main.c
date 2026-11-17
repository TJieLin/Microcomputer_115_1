/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* 波形種類：按 USER 鍵依序切換 正弦 -> 三角 -> 方波 -> 正弦 */
typedef enum
{
  WAVE_SINE = 0,
  WAVE_TRIANGLE,
  WAVE_SQUARE,
  WAVE_COUNT            /* 波形總數 = 3 */
} WaveType_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define WAVE_POINTS        100U                 /* 每個週期 100 點 */

#define USER_BTN_PORT      GPIOC                /* B1 USER 鍵 = PC13 */
#define USER_BTN_PIN       GPIO_PIN_13
#define USER_BTN_PRESSED   GPIO_PIN_SET         /* NUCLEO-G474RE：按下為高電位 */
#define USER_BTN_DEBOUNCE_MS  20U               /* 去彈跳時間 (ms) */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
DAC_HandleTypeDef hdac1;

TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */
/* 三種波形表：全部 100 點、最小值 248、最大值 3848（12-bit DAC，右對齊） */
static const uint16_t wave_table[WAVE_COUNT][WAVE_POINTS] =
{
  /* [0] 正弦波 sine_table：中心 2048、振幅 1800 */
  {
    2048, 2161, 2274, 2385, 2496, 2604, 2711, 2814, 2915, 3012,
    3106, 3195, 3280, 3360, 3435, 3504, 3568, 3625, 3677, 3722,
    3760, 3791, 3816, 3834, 3844, 3848, 3844, 3834, 3816, 3791,
    3760, 3722, 3677, 3625, 3568, 3504, 3435, 3360, 3280, 3195,
    3106, 3012, 2915, 2814, 2711, 2604, 2496, 2385, 2274, 2161,
    2048, 1935, 1822, 1711, 1600, 1492, 1385, 1282, 1181, 1084,
     990,  901,  816,  736,  661,  592,  528,  471,  419,  374,
     336,  305,  280,  262,  252,  248,  252,  262,  280,  305,
     336,  374,  419,  471,  528,  592,  661,  736,  816,  901,
     990, 1084, 1181, 1282, 1385, 1492, 1600, 1711, 1822, 1935
  },
  /* [1] 三角波：50 點上升 (每點 +72)、50 點下降 (每點 -72) */
  {
     248,  320,  392,  464,  536,  608,  680,  752,  824,  896,
     968, 1040, 1112, 1184, 1256, 1328, 1400, 1472, 1544, 1616,
    1688, 1760, 1832, 1904, 1976, 2048, 2120, 2192, 2264, 2336,
    2408, 2480, 2552, 2624, 2696, 2768, 2840, 2912, 2984, 3056,
    3128, 3200, 3272, 3344, 3416, 3488, 3560, 3632, 3704, 3776,
    3848, 3776, 3704, 3632, 3560, 3488, 3416, 3344, 3272, 3200,
    3128, 3056, 2984, 2912, 2840, 2768, 2696, 2624, 2552, 2480,
    2408, 2336, 2264, 2192, 2120, 2048, 1976, 1904, 1832, 1760,
    1688, 1616, 1544, 1472, 1400, 1328, 1256, 1184, 1112, 1040,
     968,  896,  824,  752,  680,  608,  536,  464,  392,  320
  },
  /* [2] 方波：前 50 點高電位 3848、後 50 點低電位 248 */
  {
    3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848,
    3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848,
    3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848,
    3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848,
    3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848, 3848,
     248,  248,  248,  248,  248,  248,  248,  248,  248,  248,
     248,  248,  248,  248,  248,  248,  248,  248,  248,  248,
     248,  248,  248,  248,  248,  248,  248,  248,  248,  248,
     248,  248,  248,  248,  248,  248,  248,  248,  248,  248,
     248,  248,  248,  248,  248,  248,  248,  248,  248,  248
  }
};

static volatile uint8_t wave_mode = WAVE_SINE;  /* 目前波形（主迴圈改、中斷讀） */
static uint8_t          wave_idx  = 0;          /* 目前輸出到第幾點（只在中斷內使用） */

/* 按鍵去彈跳用變數 */
static uint8_t  btn_raw_prev = 0;   /* 上一次讀到的原始狀態 */
static uint8_t  btn_stable   = 0;   /* 去彈跳後的穩定狀態 */
static uint32_t btn_tick     = 0;   /* 原始狀態最後一次變化的時間 (ms) */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DAC1_Init(void);
static void MX_TIM6_Init(void);
/* USER CODE BEGIN PFP */
static void Button_Task(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DAC1_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
  HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);           /* 啟動 DAC，PA4 開始輸出 */

  __HAL_TIM_SET_AUTORELOAD(&htim6, 199);          /* 170 MHz/170 = 1 MHz；1 MHz/200 = 5 kHz */
  __HAL_TIM_SET_COUNTER(&htim6, 0);               /* 5 kHz / 100 點 = 50 Hz */
  __HAL_TIM_CLEAR_FLAG(&htim6, TIM_FLAG_UPDATE);  /* 清掉初始化殘留的更新旗標 */
  HAL_TIM_Base_Start_IT(&htim6);                  /* 啟動 TIM6 並開啟更新中斷 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    Button_Task();                                /* 輪詢 USER 鍵（非阻塞，不用 HAL_Delay） */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief DAC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC1_Init(void)
{

  /* USER CODE BEGIN DAC1_Init 0 */

  /* USER CODE END DAC1_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC1_Init 1 */

  /* USER CODE END DAC1_Init 1 */

  /** DAC Initialization
  */
  hdac1.Instance = DAC1;
  if (HAL_DAC_Init(&hdac1) != HAL_OK)
  {
    Error_Handler();
  }

  /** DAC channel OUT1 config
  */
  sConfig.DAC_HighFrequency = DAC_HIGH_FREQUENCY_INTERFACE_MODE_AUTOMATIC;
  sConfig.DAC_DMADoubleDataMode = DISABLE;
  sConfig.DAC_SignedFormat = DISABLE;
  sConfig.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_Trigger2 = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  sConfig.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_EXTERNAL;
  sConfig.DAC_UserTrimming = DAC_TRIMMING_FACTORY;
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC1_Init 2 */

  /* USER CODE END DAC1_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 169;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 65535;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pins : LPUART1_TX_Pin LPUART1_RX_Pin */
  GPIO_InitStruct.Pin = LPUART1_TX_Pin|LPUART1_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF12_LPUART1;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* PC13 (B1 USER 鍵) 設成輸入；GPIOC 時脈上面已經開啟 */
  GPIO_InitStruct.Pin  = USER_BTN_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;           /* 按下為高電位，放開時拉低 */
  HAL_GPIO_Init(USER_BTN_PORT, &GPIO_InitStruct);
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/**
  * @brief  TIM6 更新中斷 (5 kHz)：每次送一點目前波形給 DAC1 CH1 (PA4)
  *         5 kHz / 100 點 = 50 Hz
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM6)
  {
    HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R,
                     wave_table[wave_mode][wave_idx]);

    if (++wave_idx >= WAVE_POINTS)
    {
      wave_idx = 0;
    }
  }
}

/**
  * @brief  USER 鍵 (PC13) 輪詢 + 去彈跳，每按一下切換到下一種波形
  *         用 HAL_GetTick() 比較時間，不會卡住程式
  */
static void Button_Task(void)
{
  uint8_t raw = (HAL_GPIO_ReadPin(USER_BTN_PORT, USER_BTN_PIN) == USER_BTN_PRESSED) ? 1U : 0U;

  if (raw != btn_raw_prev)
  {
    /* 狀態剛變化：記下時間，重新計時 */
    btn_raw_prev = raw;
    btn_tick = HAL_GetTick();
  }
  else if ((raw != btn_stable) && ((HAL_GetTick() - btn_tick) >= USER_BTN_DEBOUNCE_MS))
  {
    /* 狀態穩定超過 20 ms，確認是真的按下或放開 */
    btn_stable = raw;

    if (btn_stable)   /* 只在「按下」的瞬間切換 */
    {
      wave_mode = (uint8_t)((wave_mode + 1U) % WAVE_COUNT);   /* 正弦 -> 三角 -> 方波 -> 正弦 */
    }
  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
