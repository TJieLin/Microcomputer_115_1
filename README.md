# Microcomputer_115_1

##115-1 學期微算機原理及應用課程－程式碼與專案目錄。

---


<details>
<summary>Microcomputer_115_1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案根目錄</summary>
<ul>
  <li>
    <details>
      <summary>Lab01&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 說明專案內容：GPIO 基礎輪詢輸出入與按鍵控制 LED 狀態轉換實驗</summary>
      <ul>
        <li>
          <details>
            <summary>.settings&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Eclipse/STM32CubeIDE 專案編譯與除錯設定資料夾</summary>
            <ul>
              <li>language.settings.xml&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# C/C++ 語言編譯器語法解析配置</li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Core&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 核心應用程式碼目錄</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案標頭檔目錄</summary>
                  <ul>
                    <li>main.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 主程式全域標頭檔與 GPIO 引腳定義 (PA12, PB11, PB12 等)</li>
                    <li>stm32g4xx_hal_conf.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32 HAL 模組啟用與時脈參數配置檔</li>
                    <li>stm32g4xx_it.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 中斷服務常式函數原型宣告檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案 C 語言原始碼目錄</summary>
                  <ul>
                    <li>main.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 主程式進入點、系統時脈初始化與按鍵輪詢狀態機邏輯</li>
                    <li>stm32g4xx_hal_msp.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# MCU 底層外設 GPIO 初始化 (MSP) 實作</li>
                    <li>stm32g4xx_it.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Cortex-M4 系統異常與中斷服務常式實作</li>
                    <li>system_stm32g4xx.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32G4 系統時脈 (RCC/PLL) 設定與啟動邏輯</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Startup&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 開機啟動檔目錄</summary>
                  <ul>
                    <li>startup_stm32g474retx.s&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# ARM Assembly 組合語言啟動檔（設定 SP、向量表與進入 main）</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32 官方硬體驅動庫</summary>
            <ul>
              <li>
                <details>
                  <summary>CMSIS&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# ARM Cortex-M 核心標準硬體抽象層</summary>
                  <ul>
                    <li>Device/ST/STM32G4xx/Include&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32G4 暫存器結構與位址對映標頭檔</li>
                    <li>Include&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Cortex-M4 NVIC、SysTick 與 Core 內部暫存器標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>STM32G4xx_HAL_Driver&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# ST 官方 HAL C 語言驅動程式庫</summary>
                  <ul>
                    <li>Inc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL 驅動庫標頭檔 (stm32g4xx_hal_gpio.h, rcc.h, cORTEX.h 等)</li>
                    <li>Src&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL 驅動庫原始碼 (stm32g4xx_hal_gpio.c, rcc.c, cORTEX.c 等)</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Debug&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 編譯產出與除錯檔目錄</summary>
            <ul>
              <li>Lab01.elf&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 包含除錯資訊的可執行檔</li>
              <li>Lab01.hex&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 可燒錄至 MCU Flash 的十六進制唯讀燒錄檔</li>
              <li>Lab01.map&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 記憶體配置與位址映射表檔</li>
            </ul>
          </details>
        </li>
        <li>.cproject&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32CubeIDE C/C++ 專案編譯路徑與工具鏈配置檔</li>
        <li>.project&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Eclipse 專案識別與結構配置檔</li>
        <li>Lab01.ioc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32CubeMX 引腳對映、RCC 時脈與專案產生器設定檔</li>
        <li>STM32G474RETX_FLASH.ld&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Linker 連結器腳本（定義 Flash 與 SRAM 位址分配）</li>
        <li>README.md&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Lab01 實驗說明文件與電路接線說明</li>
      </ul>
    </details>
  </li>


  <li>
    <details>
      <summary>Lab02&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 說明專案內容：EXTI 外部中斷與 NVIC 向量中斷控制器實驗</summary>
      <ul>
        <li>
          <details>
            <summary>.settings&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案編譯器與除錯設定資料夾</summary>
            <ul>
              <li>language.settings.xml&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# C 語言解析設定檔</li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Core&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 核心應用程式碼目錄</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案標頭檔目錄</summary>
                  <ul>
                    <li>main.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 全域定義與中斷引腳宣告檔</li>
                    <li>stm32g4xx_hal_conf.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL 模組啟用配置檔</li>
                    <li>stm32g4xx_it.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# EXTI 外部中斷服務常式標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案 C 語言原始碼目錄</summary>
                  <ul>
                    <li>main.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 主程式與 HAL_GPIO_EXTI_Callback 中斷觸發回呼邏輯</li>
                    <li>stm32g4xx_hal_msp.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# EXTI 引腳與 NVIC 中斷優先級初始化</li>
                    <li>stm32g4xx_it.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# EXTI Line 中斷服務常式 (ISR) 實作</li>
                    <li>system_stm32g4xx.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 系統時脈與硬體基礎設定</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Startup&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 開機啟動檔目錄</summary>
                  <ul>
                    <li>startup_stm32g474retx.s&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 組合語言啟動與中斷向量表 (Vector Table) 設定檔</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32 官方硬體驅動庫</summary>
            <ul>
              <li>
                <details>
                  <summary>CMSIS&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# ARM Cortex-M 核心標準抽象層</summary>
                  <ul>
                    <li>Device/ST/STM32G4xx/Include&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# MCU 暫存器定義標頭檔</li>
                    <li>Include&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Cortex-M4 NVIC 中斷控制器標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>STM32G4xx_HAL_Driver&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL 驅動庫</summary>
                  <ul>
                    <li>Inc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL EXTI 與 GPIO 驅動標頭檔</li>
                    <li>Src&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL EXTI 與 GPIO 驅動原始碼</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Debug&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 編譯產出目錄</summary>
            <ul>
              <li>Lab02.elf&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 可執行與除錯檔</li>
              <li>Lab02.map&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 記憶體配置映射檔</li>
            </ul>
          </details>
        </li>
        <li>.cproject&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# IDE 工具鏈與編譯配置檔</li>
        <li>.project&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# IDE 專案檔</li>
        <li>Lab02.ioc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32CubeMX 中斷優先級與 EXTI 觸發模式設定檔</li>
        <li>STM32G474RETX_FLASH.ld&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Linker 連結腳本檔</li>
      </ul>
    </details>
  </li>


  <li>
    <details>
      <summary>Lab03&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 說明專案內容：Timer 定時器中斷、基頻計數與 PWM 訊號輸出控制實驗</summary>
      <ul>
        <li>
          <details>
            <summary>.settings&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案環境配置資料夾</summary>
            <ul>
              <li>language.settings.xml&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 編譯器解析設定檔</li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Core&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 核心應用程式碼目錄</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案標頭檔目錄</summary>
                  <ul>
                    <li>main.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 主程式全域宣告與 Timer 定時器設定值檔</li>
                    <li>stm32g4xx_hal_conf.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL 庫定時器 (TIM) 模組啟用檔</li>
                    <li>stm32g4xx_it.h&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 定時器更新中斷 (Update Interrupt) 標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 專案 C 語言原始碼目錄</summary>
                  <ul>
                    <li>main.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 主程式、HAL_TIM_PeriodElapsedCallback 定時器計數與 PWM 占空比調節</li>
                    <li>stm32g4xx_hal_msp.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# TIM 定時器時脈源與 Channel PWM Pin 腳初始化</li>
                    <li>stm32g4xx_it.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 定時器溢位中斷服務常式實作</li>
                    <li>system_stm32g4xx.c&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 系統時脈設定檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Startup&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 開機啟動檔目錄</summary>
                  <ul>
                    <li>startup_stm32g474retx.s&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 啟動與中斷向量表設檔</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32 官方硬體驅動庫</summary>
            <ul>
              <li>
                <details>
                  <summary>CMSIS&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# ARM Cortex-M 核心標準抽象層</summary>
                  <ul>
                    <li>Device/ST/STM32G4xx/Include&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 暫存器定義標頭檔</li>
                    <li>Include&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Cortex-M4 核心標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>STM32G4xx_HAL_Driver&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL 驅動庫</summary>
                  <ul>
                    <li>Inc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL TIM 定時器與 PWM 驅動標頭檔</li>
                    <li>Src&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# HAL TIM 定時器與 PWM 驅動原始碼</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Debug&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 編譯產出目錄</summary>
            <ul>
              <li>Lab03.elf&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 可執行檔</li>
              <li>Lab03.map&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 記憶體配置映射檔</li>
            </ul>
          </details>
        </li>
        <li>.cproject&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# IDE 編譯配置檔</li>
        <li>.project&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# IDE 專案檔</li>
        <li>Lab03.ioc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# STM32CubeMX 定時器預分頻器 (Prescaler) 與重裝載值 (ARR) 設定檔</li>
        <li>STM32G474RETX_FLASH.ld&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Linker 連結腳本檔</li>
      </ul>
    </details>
  </li>


  <li>.gitignore&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Git 忽略版本控制設定檔（包含 *.o, *.elf 等暫存檔過濾）</li>
  <li>README.md&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# 本儲存庫主說明文件</li>
</ul>
</details>
