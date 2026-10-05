# Microcomputer_115_1
<details>
<summary><b>點擊展開 / 收合 專案目錄結構</b></summary>

# Microcomputer_115_1

本儲存庫包含 115-1 學期微處理機/微電腦單晶片課程之實驗程式碼、專案實作與硬體設定檔。主要基於 STM32 微控制器開發，內容涵蓋 GPIO、中斷、計時器 (Timer)、UART 通訊及綜合專案實作。

---

## 📂 檔案架構與專案說明

> 💡 點擊下方資料夾名稱可展開/收合詳細檔案列表

<details>
<summary>📁 <b>Lab01_GPIO_LED</b> - # 說明專案內容：按鍵與 LED 基礎 GPIO 輸出入控制實驗</summary>

* 📁 **Core/** - # 核心程式碼資料夾
  * 📁 **Inc/** - # 標頭檔目錄
    * 📄 `main.h` - # 主程式標頭檔與引腳定義
    * 📄 `stm32g4xx_it.h` - # 中斷服務常式標頭檔
  * 📁 **Src/** - # 原始碼目錄
    * 📄 `main.c` - # 主程式邏輯（GPIO 初始化與 LED 輪詢控制）
    * 📄 `stm32g4xx_it.c` - # 中斷服務常式實作
* 📄 `Lab01_GPIO_LED.ioc` - # STM32CubeMX 圖形化引腳與時脈設定檔
* 📄 `README.md` - # Lab01 實驗說明文件與硬體接線圖
</details>

<details>
<summary>📁 <b>Lab02_Button_Interrupt</b> - # 說明專案內容：EXTI 外部中斷與按鍵去彈跳實作</summary>

* 📁 **Core/** - # 核心程式碼資料夾
  * 📁 **Inc/** - # 標頭檔目錄
    * 📄 `main.h` - # 引腳與系統標頭檔
    * 📄 `stm32g4xx_it.h` - # 中斷處理標頭檔
  * 📁 **Src/** - # 原始碼目錄
    * 📄 `main.c` - # 主程式與 EXTI 中斷回呼函數 (Callback)
    * 📄 `stm32g4xx_it.c` - # 外部中斷 Handler 實作
* 📄 `Lab02_Button_Interrupt.ioc` - # CubeMX 中斷與 NVIC 設定檔
</details>

<details>
<summary>📁 <b>Lab03_Timer_PWM</b> - # 說明專案內容：Timer 定時器中斷與 PWM 呼吸燈控制</summary>

* 📁 **Core/** - # 核心程式碼資料夾
  * 📁 **Inc/** - # 標頭檔目錄
    * 📄 `main.h` - # 系統配置標頭檔
    * 📄 `timer.h` - # 定時器與 PWM 功能函式標頭檔
  * 📁 **Src/** - # 原始碼目錄
    * 📄 `main.c` - # 主程式與 PWM 占空比調節邏輯
    * 📄 `timer.c` - # 定時器初始化與 PWM 設定實作
* 📄 `Lab03_Timer_PWM.ioc` - # 定時器與 PWM 通道 CubeMX 設定檔
</details>

<details>
<summary>📁 <b>Lab04_UART_Communication</b> - # 說明專案內容：UART 序列埠異步通訊與資料傳輸</summary>

* 📁 **Core/** - # 核心程式碼資料夾
  * 📁 **Inc/** - # 標頭檔目錄
    * 📄 `main.h` - # 專案主標頭檔
    * 📄 `usart.h` - # UART 收發函式標頭檔
  * 📁 **Src/** - # 原始碼目錄
    * 📄 `main.c` - # 主程式（UART 命令解析與字串印出）
    * 📄 `usart.c` - # UART 硬體驅動與收發實作
* 📄 `Lab04_UART_Communication.ioc` - # 波特率與 UART 引腳設定檔
</details>

<details>
<summary>📁 <b>Project_Final</b> - # 說明專案內容：微電腦單晶片期末綜合專案實作</summary>

* 📁 **Core/** - # 核心程式碼資料夾
  * 📁 **Inc/** - # 標頭檔目錄
    * 📄 `main.h` - # 專案全域配置標頭檔
    * 📄 `display.h` - # 顯示器（如 LCD/OLED）驅動標頭檔
    * 📄 `sensor.h` - # 感測器讀取驅動標頭檔
  * 📁 **Src/** - # 原始碼目錄
    * 📄 `main.c` - # 專案主要狀態機與控制流程
    * 📄 `display.c` - # 顯示介面控制邏輯實作
    * 📄 `sensor.c` - # 感測器資料採集與處理解析
* 📁 **Hardware/** - # 硬體相關資料目錄
  * 📄 `schematic.pdf` - # 系統電路原理圖
  * 📄 `pinout_mapping.png` - # 開發板引腳對接腳位圖
* 📄 `Project_Final.ioc` - # 期末專案 CubeMX 完整系統設定檔
* 📄 `README.md` - # 期末專案報告與展示說明
</details>

* 📄 `.gitignore` - # Git 忽略版本控制設定檔
* 📄 `README.md` - # 本儲存庫主說明文件
