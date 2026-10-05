
# Microcomputer_115_1

115-1 學期微算機原理及應用課程－程式碼與專案目錄。

---

## 專案檔案結構

<details>
<summary>Microcomputer_115_1             # 專案根目錄</summary>


<ul>
  <li>
    <details>
      <summary>Lab01             # 說明專案內容：GPIO 基礎輪詢輸出入與按鍵控制 LED 狀態轉換實驗</summary>
      <ul>
        <li>
          <details>
            <summary>.settings             # Eclipse/STM32CubeIDE 專案編譯與除錯設定資料夾</summary>
            <ul>
              <li>language.settings.xml             # C/C++ 語言編譯器語法解析配置</li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Core             # 核心應用程式碼目錄</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc             # 專案標頭檔目錄</summary>
                  <ul>
                    <li>main.h             # 主程式全域標頭檔與 GPIO 引腳定義 (PA12, PB11, PB12 等)</li>
                    <li>stm32g4xx_hal_conf.h             # STM32 HAL 模組啟用與時脈參數配置檔</li>
                    <li>stm32g4xx_it.h             # 中斷服務常式函數原型宣告檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src             # 專案 C 語言原始碼目錄</summary>
                  <ul>
                    <li>main.c             # 主程式進入點、系統時脈初始化與按鍵輪詢狀態機邏輯</li>
                    <li>stm32g4xx_hal_msp.c             # MCU 底層外設 GPIO 初始化 (MSP) 實作</li>
                    <li>stm32g4xx_it.c             # Cortex-M4 系統異常與中斷服務常式實作</li>
                    <li>system_stm32g4xx.c             # STM32G4 系統時脈 (RCC/PLL) 設定與啟動邏輯</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Startup             # 開機啟動檔目錄</summary>
                  <ul>
                    <li>startup_stm32g474retx.s             # ARM Assembly 組合語言啟動檔（設定 SP、向量表與進入 main）</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers             # STM32 官方硬體驅動庫</summary>
            <ul>
              <li>
                <details>
                  <summary>CMSIS             # ARM Cortex-M 核心標準硬體抽象層</summary>
                  <ul>
                    <li>Device/ST/STM32G4xx/Include             # STM32G4 暫存器結構與位址對映標頭檔</li>
                    <li>Include             # Cortex-M4 NVIC、SysTick 與 Core 內部暫存器標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>STM32G4xx_HAL_Driver             # ST 官方 HAL C 語言驅動程式庫</summary>
                  <ul>
                    <li>Inc             # HAL 驅動庫標頭檔 (stm32g4xx_hal_gpio.h, rcc.h, cORTEX.h 等)</li>
                    <li>Src             # HAL 驅動庫原始碼 (stm32g4xx_hal_gpio.c, rcc.c, cORTEX.c 等)</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Debug             # 編譯產出與除錯檔目錄</summary>
            <ul>
              <li>Lab01.elf             # 包含除錯資訊的可執行檔</li>
              <li>Lab01.hex             # 可燒錄至 MCU Flash 的十六進制唯讀燒錄檔</li>
              <li>Lab01.map             # 記憶體配置與位址映射表檔</li>
            </ul>
          </details>
        </li>
        <li>.cproject             # STM32CubeIDE C/C++ 專案編譯路徑與工具鏈配置檔</li>
        <li>.project             # Eclipse 專案識別與結構配置檔</li>
        <li>Lab01.ioc             # STM32CubeMX 引腳對映、RCC 時脈與專案產生器設定檔</li>
        <li>STM32G474RETX_FLASH.ld             # Linker 連結器腳本（定義 Flash 與 SRAM 位址分配）</li>
        <li>README.md             # Lab01 實驗說明文件與電路接線說明</li>
      </ul>
    </details>
  </li>


  <li>
    <details>
      <summary>Lab02             # 說明專案內容：EXTI 外部中斷與 NVIC 向量中斷控制器實驗</summary>
      <ul>
        <li>
          <details>
            <summary>.settings             # 專案編譯器與除錯設定資料夾</summary>
            <ul>
              <li>language.settings.xml             # C 語言解析設定檔</li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Core             # 核心應用程式碼目錄</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc             # 專案標頭檔目錄</summary>
                  <ul>
                    <li>main.h             # 全域定義與中斷引腳宣告檔</li>
                    <li>stm32g4xx_hal_conf.h             # HAL 模組啟用配置檔</li>
                    <li>stm32g4xx_it.h             # EXTI 外部中斷服務常式標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src             # 專案 C 語言原始碼目錄</summary>
                  <ul>
                    <li>main.c             # 主程式與 HAL_GPIO_EXTI_Callback 中斷觸發回呼邏輯</li>
                    <li>stm32g4xx_hal_msp.c             # EXTI 引腳與 NVIC 中斷優先級初始化</li>
                    <li>stm32g4xx_it.c             # EXTI Line 中斷服務常式 (ISR) 實作</li>
                    <li>system_stm32g4xx.c             # 系統時脈與硬體基礎設定</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Startup             # 開機啟動檔目錄</summary>
                  <ul>
                    <li>startup_stm32g474retx.s             # 組合語言啟動與中斷向量表 (Vector Table) 設定檔</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers             # STM32 官方硬體驅動庫</summary>
            <ul>
              <li>
                <details>
                  <summary>CMSIS             # ARM Cortex-M 核心標準抽象層</summary>
                  <ul>
                    <li>Device/ST/STM32G4xx/Include             # MCU 暫存器定義標頭檔</li>
                    <li>Include             # Cortex-M4 NVIC 中斷控制器標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>STM32G4xx_HAL_Driver             # HAL 驅動庫</summary>
                  <ul>
                    <li>Inc             # HAL EXTI 與 GPIO 驅動標頭檔</li>
                    <li>Src             # HAL EXTI 與 GPIO 驅動原始碼</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Debug             # 編譯產出目錄</summary>
            <ul>
              <li>Lab02.elf             # 可執行與除錯檔</li>
              <li>Lab02.map             # 記憶體配置映射檔</li>
            </ul>
          </details>
        </li>
        <li>.cproject             # IDE 工具鏈與編譯配置檔</li>
        <li>.project             # IDE 專案檔</li>
        <li>Lab02.ioc             # STM32CubeMX 中斷優先級與 EXTI 觸發模式設定檔</li>
        <li>STM32G474RETX_FLASH.ld             # Linker 連結腳本檔</li>
      </ul>
    </details>
  </li>


  <li>
    <details>
      <summary>Lab03             # 說明專案內容：Timer 定時器中斷、基頻計數與 PWM 訊號輸出控制實驗</summary>
      <ul>
        <li>
          <details>
            <summary>.settings             # 專案環境配置資料夾</summary>
            <ul>
              <li>language.settings.xml             # 編譯器解析設定檔</li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Core             # 核心應用程式碼目錄</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc             # 專案標頭檔目錄</summary>
                  <ul>
                    <li>main.h             # 主程式全域宣告與 Timer 定時器設定值檔</li>
                    <li>stm32g4xx_hal_conf.h             # HAL 庫定時器 (TIM) 模組啟用檔</li>
                    <li>stm32g4xx_it.h             # 定時器更新中斷 (Update Interrupt) 標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src             # 專案 C 語言原始碼目錄</summary>
                  <ul>
                    <li>main.c             # 主程式、HAL_TIM_PeriodElapsedCallback 定時器計數與 PWM 占空比調節</li>
                    <li>stm32g4xx_hal_msp.c             # TIM 定時器時脈源與 Channel PWM Pin 腳初始化</li>
                    <li>stm32g4xx_it.c             # 定時器溢位中斷服務常式實作</li>
                    <li>system_stm32g4xx.c             # 系統時脈設定檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Startup             # 開機啟動檔目錄</summary>
                  <ul>
                    <li>startup_stm32g474retx.s             # 啟動與中斷向量表設檔</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers             # STM32 官方硬體驅動庫</summary>
            <ul>
              <li>
                <details>
                  <summary>CMSIS             # ARM Cortex-M 核心標準抽象層</summary>
                  <ul>
                    <li>Device/ST/STM32G4xx/Include             # 暫存器定義標頭檔</li>
                    <li>Include             # Cortex-M4 核心標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>STM32G4xx_HAL_Driver             # HAL 驅動庫</summary>
                  <ul>
                    <li>Inc             # HAL TIM 定時器與 PWM 驅動標頭檔</li>
                    <li>Src             # HAL TIM 定時器與 PWM 驅動原始碼</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Debug             # 編譯產出目錄</summary>
            <ul>
              <li>Lab03.elf             # 可執行檔</li>
              <li>Lab03.map             # 記憶體配置映射檔</li>
            </ul>
          </details>
        </li>
        <li>.cproject             # IDE 編譯配置檔</li>
        <li>.project             # IDE 專案檔</li>
        <li>Lab03.ioc             # STM32CubeMX 定時器預分頻器 (Prescaler) 與重裝載值 (ARR) 設定檔</li>
        <li>STM32G474RETX_FLASH.ld             # Linker 連結腳本檔</li>
      </ul>
    </details>
  </li>


  <li>.gitignore             # Git 忽略版本控制設定檔（包含 *.o, *.elf 等暫存檔過濾）</li>
  <li>README.md             # 本儲存庫主說明文件</li>
</ul>
</details>
