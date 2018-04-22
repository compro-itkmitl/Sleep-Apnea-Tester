# Sleep Apnea Tester
&nbsp;&nbsp;&nbsp;&nbsp;Sleep Apnea Tester is a micro-controller project for Computer Programming 2017 with two main objectives are Sleep Apnea surveillance and report abnormal results while sleeping.
  
&nbsp;&nbsp;&nbsp;&nbsp;Presently, the problem in sleeping was increase and these problems can risk assessment in diseases. Sleep Apnea Tester can solve sleep problem by respiratory rate measure, snore check and others while sleeping with Sound Microphone Detection Module. The result will be saved and can be checking to signify irregularity while sleeping if the irregularity was found while sleeping, the user can consult with paramedic for protecting in long term.

#### &nbsp;&nbsp;&nbsp;&nbsp;** ***Sleep Apnea Risk Test Program and Sleep Apnea Board Meter is only predict sleep apnea disease's risk. If you found the high risk, please go to see a doctor!*** **

---

# ![](/Self-evaluation/img/how_to_icon.png) Installation
1. **Download and Install Arduino IDE**
  - Go to https://www.arduino.cc/ and click on **SOFTWARE** menu and select **DOWNLOADS**.
  
    ![](/Self-evaluation/img/step_1_1.png)
  
  - Select computer's operating system for coding on Arduino IDE.
  
    ![](/Self-evaluation/img/step_1_2.png)
    
  - Click on **JUST DOWNLOAD** for download program or **CONTRIBUTE & DOWNLOAD** for donate developer and download program.
  
    ![](/Self-evaluation/img/step_1_3.png)
    
  - Unzip the file and run arduino.exe for installation Arduino IDE.

---

2. **Setting Arduino IDE**
  - Go to File >> Preference, it will show preference window.
  - Pasted http://arduino.esp8266.com/stable/package_esp8266com_index.json in **Additional Boards Manager URLs** and click **OK**.
  
  ![](/Self-evaluation/img/step_2_1.png)

---
  
3. **Download and Install Driver**
  - Go to https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers.
  - Select computer's operating system for download software.
  
  ![](/Self-evaluation/img/step_3_1.png)

  - Install the driver on the computer.

---

4. **Download and Install Library**
  - Go to https://github.com/compro-itkmitl/Sleep-Apnea-Tester/tree/master/Library
  - Download all ZIP file.
  
  ![](/Self-evaluation/img/step_4_1.png)
  
  - Open Arduino IDE and select Sketch >> Include Library >> Add .zip library.
  
  ![](/Self-evaluation/img/step_4_2.png)
  
  - Select ZIP file and click on "open".

---

# ![](/Self-evaluation/img/library.png) Library In Uses
  - Arduino Json : https://github.com/bblanchon/ArduinoJson
  - Time Library : https://github.com/PaulStoffregen/Time
  - Firebase Arduino : https://github.com/firebase/firebase-arduino
  - Pubsubclient : https://github.com/knolleary/pubsubclient
---

# ![](/Self-evaluation/img/requirement_icon.png) Requirements
Arduino UNO R3 | USB | Jumper | High Sensitive sound Microphone Detection Module
:-: | :-: | :-: | :-:
![](/Self-evaluation/img/arduino.png) | ![](/Self-evaluation/img/usb.png) | ![](/Self-evaluation/img/jumper.png) | ![](/Self-evaluation/img/sound_module.png) ![](/Self-evaluation/img/sound_module.png)

Data Logger Shield | Breadboard | SD card  | Lithium Cell CR122 | Cmd with Gcc
:-: | :-: | :-: | :-: | :-:
![](/Self-evaluation/img/data_shield.png) | ![](/Self-evaluation/img/bread_board.png) | ![](/Self-evaluation/img/sd_card.png) | ![](/Self-evaluation/img/cell.png) | ![](/Self-evaluation/img/gcc.png)

>&nbsp;&nbsp;&nbsp;&nbsp;If you don't have GCC compiler yet, you can install this.
>
> MINGW gcc Compiler : https://sourceforge.net/projects/tdm-gcc/

---

# ![](/Self-evaluation/img/board_icon.png) Board Connection

![](/Self-evaluation/img/2arduino.png)
![](/Self-evaluation/img/Board.png)
![](/Self-evaluation/img/arduino uno.png)

**Connection**
  1. Connect Arduino UNO R3 with Data Logger Shield with headers.
  2. Connect Data Logger Shield's 5v port to Board Bread's pin3w and GND port to Board Bread's pin3x.
  3. Connect Sound Microphone Detection's Vcc port to Board Bread's pin5w and another Sound Microphone Detection's Vcc port to Board Bread's pin7w.
  4. Connect Sound Microphone Detection's GND port to Board Bread's pin5x and pin7x same as Sound Microphone Detection's Vcc port are connected.
  5. Connect Sound Microphone Detection's output port to Data Logger Shield's Digital I/O at D2 and D3.
  
![](/Self-evaluation/img/FinishBoard.jpg)

---

# ![](/Self-evaluation/img/step_icon.png) How to use

**Part I: Sleep Apnea Risk Test Program**

&nbsp;&nbsp;&nbsp;&nbsp;For check risk to be Sleep Apnea Syndrome apart from "Sleep Apnea Board Meter".

1. Download Adultandchild.c from https://github.com/compro-itkmitl/Sleep-Apnea-Tester/blob/master/Self-evaluation/Risk's%20Self-evaluation/Sleep%20Apnea%20Risk%20Test.c
2. Open the Command Prompt (CMD Commands) and Change Directory to this file then type '**gcc Sleep Apnea Risk Test.c**' for compile the code. 
3. Type '**a**' on command for run the program.
4. Waiting for the program in running for a minute.
5. Let's do this Sleep Apnea Risk Test!

>&nbsp;&nbsp;&nbsp;&nbsp;**Tips: Disable Avast CyberCapture Completely**
>
>&nbsp;&nbsp;&nbsp;&nbsp;If you compile by type: '**gcc Sleep Apnea Risk Test.c -o a.out**' and run by type: '**.\a.out**'. Avast >CyberCapture will appear on the screen.To completely turn off CyberCapture in your Avast antivirus follow these steps:
>    1. Open Avast user interface and go to settings.
>    2. In the 'General' tab (first item) uncheck '**Enable CyberCapture**'
>    3. Confirm by clicking the '**OK**' button
>
>![](/Self-evaluation/img/avast_setting.png)


**Part II : Sleep Apnea Board Meter**
  1. Open Stop_breath_check file: https://github.com/compro-itkmitl/Sleep-Apnea-Tester/blob/master/breathe/Stop_breath_check/Stop_breath_check.ino
  2. Go to Tools >> Board then select '**Arduino/Genuino Uno**'.
  3. Select Serial Port for connect USB.
  4. Connect USB for start using, the yellow light sensor for nose breath measure and the green light for month breath measure.
  
  ![](/Self-evaluation/img/Sound_sensors.png)
  
  5. The output will show at the real-time in Serial Monitor. If you finish already, you can shutdown it immediately.
 
  ![](/Self-evaluation/img/SerialMonitor.jpg)
  
  6. The record will save at OUTPUT.txt on SD Card.

  ![](/Self-evaluation/img/SDcardOutput.jpg)
  
---

# ![](/Self-evaluation/img/assis_icon.png) Software We Use
Arduino | Fritzing | gcc Compiler
:-: | :-: | :-: | :-: | :-:
![](/Self-evaluation/img/arduino_logo.png) | ![](/Self-evaluation/img/Fritzing.png) | ![](/Self-evaluation/img/tdmgcc1.png)

---

# ![](/Self-evaluation/img/rsz_team-icon.png) Members
ID | First Name | Surname | GitHub Username
--- | --- | ---
60070016 | Chaiyapong | Nithipeerawat | [@Sullvo1147](https://github.com/Sullvo1147)
60070018 | Thitikorn | Padungwatsawat | [@maxlunla](https://github.com/maxlunla)
60070034 | Thirada | Theethum | [@PrintTrd](https://github.com/PrintTrd)

---

# ![](/Self-evaluation/img/assis_icon.png) Assistant Teacher
Assist.Prof. Dr. Kitsuchart Pasupa | Assist.Prof. Dr. Panwit Tuwanut
|:-:|:-:|
|![](/Self-evaluation/img/teacher_kitsuchart.png) | ![](/Self-evaluation/img/teacher_panwit.png)|

---

Faculty of Information Technology

King Mongkut's Institute of Technology Ladkrabang
