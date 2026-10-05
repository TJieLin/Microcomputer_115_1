# Microcomputer_115_1
<details>
<summary><b>點擊展開 / 收合 專案目錄結構</b></summary>

115-1 學期微處理機課程實驗程式碼與專案目錄。

---

## 專案檔案結構

<details>
<summary>Microcomputer_115_1 # 專案根目錄</summary>
<ul>
  <li>
    <details>
      <summary>Lab01 # 說明專案內容：GPIO 基礎輸出入與 LED 控制實驗</summary>
      <ul>
        <li>
          <details>
            <summary>Core</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc # 標頭檔目錄</summary>
                  <ul>
                    <li>main.h # 主程式標頭檔與引腳定義</li>
                    <li>stm32g4xx_hal_conf.h # HAL 庫配置檔</li>
                    <li>stm32g4xx_it.h # 中斷處理標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src # 原始碼目錄</summary>
                  <ul>
                    <li>main.c # 主程式邏輯與 GPIO 輪詢控制</li>
                    <li>stm32g4xx_hal_msp.c # HAL 庫 MCU 層級硬體初始化</li>
                    <li>stm32g4xx_it.c # 中斷服務常式實作</li>
                    <li>system_stm32g4xx.c # 系統時脈與硬體基礎設定</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers # STM32 官方驅動庫目錄</summary>
            <ul>
              <li>CMSIS # ARM CMSIS 核心介面驅動</li>
              <li>STM32G4xx_HAL_Driver # STM32G4 HAL 硬體抽象層驅動</li>
            </ul>
          </details>
        </li>
        <li>Lab01.ioc # STM32CubeMX 圖形化引腳與時脈設定檔</li>
        <li>STM32G474RETX_FLASH.ld # 記憶體配置與 Linker 腳本</li>
        <li>README.md # Lab01 實驗說明文件</li>
      </ul>
    </details>
  </li>
  <li>
    <details>
      <summary>Lab02 # 說明專案內容：按鍵中斷與 EXTI 觸發控制實驗</summary>
      <ul>
        <li>
          <details>
            <summary>Core</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc # 標頭檔目錄</summary>
                  <ul>
                    <li>main.h # 主程式標頭檔</li>
                    <li>stm32g4xx_hal_conf.h # HAL 庫配置檔</li>
                    <li>stm32g4xx_it.h # 中斷處理標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src # 原始碼目錄</summary>
                  <ul>
                    <li>main.c # 主程式與外部中斷 Callback 邏輯</li>
                    <li>stm32g4xx_hal_msp.c # MCU 層級初始化</li>
                    <li>stm32g4xx_it.c # 外部中斷服務常式</li>
                    <li>system_stm32g4xx.c # 系統時脈設定</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers # STM32 官方驅動庫目錄</summary>
            <ul>
              <li>CMSIS # ARM CMSIS 核心驅動</li>
              <li>STM32G4xx_HAL_Driver # STM32G4 HAL 驅動庫</li>
            </ul>
          </details>
        </li>
        <li>Lab02.ioc # STM32CubeMX 中斷與 NVIC 設定檔</li>
        <li>STM32G474RETX_FLASH.ld # Linker 腳本</li>
      </ul>
    </details>
  </li>
  <li>
    <details>
      <summary>Lab03 # 說明專案內容：Timer 定時器中斷與 PWM 計時控制實驗</summary>
      <ul>
        <li>
          <details>
            <summary>Core</summary>
            <ul>
              <li>
                <details>
                  <summary>Inc # 標頭檔目錄</summary>
                  <ul>
                    <li>main.h # 主程式標頭檔</li>
                    <li>stm32g4xx_hal_conf.h # HAL 庫配置檔</li>
                    <li>stm32g4xx_it.h # 中斷處理標頭檔</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>Src # 原始碼目錄</summary>
                  <ul>
                    <li>main.c # 主程式與 Timer / PWM 占空比控制</li>
                    <li>stm32g4xx_hal_msp.c # 定時器外設硬體初始化</li>
                    <li>stm32g4xx_it.c # 定時器中斷服務常式</li>
                    <li>system_stm32g4xx.c # 系統時脈設定</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>Drivers # STM32 官方驅動庫目錄</summary>
            <ul>
              <li>CMSIS # ARM CMSIS 核心驅動</li>
              <li>STM32G4xx_HAL_Driver # STM32G4 HAL 驅動庫</li>
            </ul>
          </details>
        </li>
        <li>Lab03.ioc # STM32CubeMX 定時器與 PWM 設定檔</li>
        <li>STM32G474RETX_FLASH.ld # Linker 腳本</li>
      </ul>
    </details>
  </li>
  <li>.gitignore # Git 忽略設定檔</li>
  <li>README.md # 本儲存庫說明文件</li>
</ul>
</details>
