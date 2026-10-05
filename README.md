# Microcomputer_115_1
<details>
<summary><b>點擊展開 / 收合 專案目錄結構</b></summary>

# Microcomputer_115_1

本儲存庫為 **115-1 學期微處理機 / 微電腦單晶片課程**（Microcomputer Principles and Applications）之實驗程式碼、專案與相關硬體開發紀錄。內容涵蓋韌體開發、GPIO 控制、中斷處理、定時器 (Timer)、通訊協定 (UART/SPI/I2C) 等相關實驗範例與成果。

---

## 📂 專案檔案結構 (Project Directory Structure)

> 💡 **點擊資料夾即可展開或收合內部檔案目錄**

<details>
<summary>📁 <b>Microcomputer_115_1</b> (Root Domain)</summary>
<ul>
  <li>
    <details>
      <summary>📁 <b>Lab01_GPIO_LED</b></summary>
      <ul>
        <li>
          <details>
            <summary>📁 <b>Core</b></summary>
            <ul>
              <li>
                <details>
                  <summary>📁 <b>Inc</b></summary>
                  <ul>
                    <li>📄 main.h</li>
                    <li>📄 stm32g4xx_hal_conf.h</li>
                    <li>📄 stm32g4xx_it.h</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>📁 <b>Src</b></summary>
                  <ul>
                    <li>📄 main.c</li>
                    <li>📄 stm32g4xx_hal_msp.c</li>
                    <li>📄 stm32g4xx_it.c</li>
                    <li>📄 system_stm32g4xx.c</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>📁 <b>Drivers</b></summary>
            <ul>
              <li>📁 CMSIS</li>
              <li>📁 STM32G4xx_HAL_Driver</li>
            </ul>
          </details>
        </li>
        <li>📄 Lab01_GPIO_LED.ioc</li>
        <li>📄 STM32G474RETX_FLASH.ld</li>
        <li>📄 README.md</li>
      </ul>
    </details>
  </li>
  <li>
    <details>
      <summary>📁 <b>Lab02_Button_Interrupt</b></summary>
      <ul>
        <li>
          <details>
            <summary>📁 <b>Core</b></summary>
            <ul>
              <li>
                <details>
                  <summary>📁 <b>Inc</b></summary>
                  <ul>
                    <li>📄 main.h</li>
                    <li>📄 stm32g4xx_it.h</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>📁 <b>Src</b></summary>
                  <ul>
                    <li>📄 main.c</li>
                    <li>📄 stm32g4xx_it.c</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>📄 Lab02_Button_Interrupt.ioc</li>
        <li>📄 README.md</li>
      </ul>
    </details>
  </li>
  <li>
    <details>
      <summary>📁 <b>Lab03_Timer_PWM</b></summary>
      <ul>
        <li>
          <details>
            <summary>📁 <b>Core</b></summary>
            <ul>
              <li>
                <details>
                  <summary>📁 <b>Inc</b></summary>
                  <ul>
                    <li>📄 main.h</li>
                    <li>📄 timer.h</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>📁 <b>Src</b></summary>
                  <ul>
                    <li>📄 main.c</li>
                    <li>📄 timer.c</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>📄 Lab03_Timer_PWM.ioc</li>
      </ul>
    </details>
  </li>
  <li>
    <details>
      <summary>📁 <b>Lab04_UART_Communication</b></summary>
      <ul>
        <li>
          <details>
            <summary>📁 <b>Core</b></summary>
            <ul>
              <li>
                <details>
                  <summary>📁 <b>Inc</b></summary>
                  <ul>
                    <li>📄 main.h</li>
                    <li>📄 usart.h</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>📁 <b>Src</b></summary>
                  <ul>
                    <li>📄 main.c</li>
                    <li>📄 usart.c</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>📄 Lab04_UART_Communication.ioc</li>
      </ul>
    </details>
  </li>
  <li>
    <details>
      <summary>📁 <b>Project_Final</b></summary>
      <ul>
        <li>
          <details>
            <summary>📁 <b>Core</b></summary>
            <ul>
              <li>
                <details>
                  <summary>📁 <b>Inc</b></summary>
                  <ul>
                    <li>📄 main.h</li>
                    <li>📄 display.h</li>
                    <li>📄 sensor.h</li>
                  </ul>
                </details>
              </li>
              <li>
                <details>
                  <summary>📁 <b>Src</b></summary>
                  <ul>
                    <li>📄 main.c</li>
                    <li>📄 display.c</li>
                    <li>📄 sensor.c</li>
                  </ul>
                </details>
              </li>
            </ul>
          </details>
        </li>
        <li>
          <details>
            <summary>📁 <b>Hardware</b></summary>
            <ul>
              <li>📄 schematic.pdf</li>
              <li>📄 pinout_mapping.png</li>
            </ul>
          </details>
        </li>
        <li>📄 Project_Final.ioc</li>
        <li>📄 README.md</li>
      </ul>
    </details>
  </li>
  <li>📄 .gitignore</li>
  <li>📄 README.md</li>
</ul>
</details>
