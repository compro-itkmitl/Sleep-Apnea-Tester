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
  - Go to Sleep-Apnea-Tester >> Library
  - Extract all ZIP file.  
  - Open Arduino IDE and select Sketch >> Include Library >> Add .zip library.
  
  ![](/Self-evaluation/img/step_4_2.png)
  
  - Select ZIP file and click on "open".

---

# ![](/Self-evaluation/img/library.png) Library In Uses
  Sleep Apnea Board Meter
  - Time Library : https://github.com/PaulStoffregen/Time
  - DS1307RTC Library : https://github.com/PaulStoffregen/DS1307RTC
  - SD Library
  
  Sleep Apnea Risk Test Program
  - <time.h> : time(), localtime()
  - <stdlib.h> : system("cls")

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

![](/Self-evaluation/img/2arduino.jpg) ![](/Self-evaluation/img/Board.png)
> Thanks for "[Fritzing](http://fritzing.org/home/)", to create the design of arduino boards.

**Connection**
  1. Connect Arduino UNO R3 with Data Logger Shield with headers.
  2. Connect Data Logger Shield's 5v port and GND to Board Bread's pin.
  3. Connect Sound Microphone Detection's GND port and VCC port to Board Bread's pin for received electric from 5v port.
  4. Connect Sound Microphone Detection's output port to Data Logger Shield's Digital I/O at D2 and D3 for send output to Data Logger Shield.
  
![](/Self-evaluation/img/FinishBoard.jpg)

---

# ![](/Self-evaluation/img/step_icon.png) How to use

**Part I: Sleep Apnea Risk Test Program**

&nbsp;&nbsp;&nbsp;&nbsp;For check risk to be Sleep Apnea Syndrome apart from "Sleep Apnea Board Meter".

>&nbsp;&nbsp;&nbsp;&nbsp;**Tips: Disable Avast CyberCapture Completely**
>
>&nbsp;&nbsp;&nbsp;&nbsp;You should turn off CyberCapture in your Avast antivirus first, because Avast CyberCapture will appear on the screen. You can follow these steps:
>    1. Open Avast user interface and go to settings.
>    2. In the 'General' tab (first item) uncheck '**Enable CyberCapture**'
>    3. Confirm by clicking the '**OK**' button
>
>![](/Self-evaluation/img/avast_setting.png)

1. Download Adultandchild.c from https://github.com/compro-itkmitl/Sleep-Apnea-Tester/blob/master/Real%20use/Sleep%20Apnea%20Risk%20Test.c
2. Open file **Sleep Apnea Risk Test.c** and Change Directory to folder that you want to save the result

![](/Self-evaluation/img/selfedit.png)

2. Save file and open the Command Prompt (CMD Commands) and Change Directory to this file then type '**gcc Sleep Apnea Risk Test.c**' for compile the code. 
3. Type '**a**' on command for run the program.

![](/Self-evaluation/img/compile.png)

4. Waiting for the program in running for a minute.
5. Let's do this Sleep Apnea Risk Test!

![](/Self-evaluation/img/output.png)

>Output on Command Prompt (CMD Commands)

**Part II : Sleep Apnea Board Meter**
  1. Download and Run folder: https://github.com/compro-itkmitl/Sleep-Apnea-Tester/tree/master/Real%20use/Stop_breath_check
  2. Go to Tools >> Board then select '**Arduino/Genuino Uno**'.
  3. Select Serial Port for connect USB.
  4. Connect USB for start using, the yellow light sensor for nose breath measure and the green light for month breath measure.
  
  ![](/Self-evaluation/img/Sound_sensors.png)
  
  5. The output will show at the real-time in Serial Monitor. If you already finish, you can immediately shutdown.
 
  ![](/Self-evaluation/img/SerialMonitor.jpg)
  
  6. The record will save at OUTPUT.txt on SD Card.

  ![](/Self-evaluation/img/SDcardOutput.jpg)
  
---

# ![](/Self-evaluation/img/rsz_team-icon.png) Members
&nbsp; | ID | First Name | Surname | GitHub Username |
:-: | :-: | :-: | :-: | :-:
![](/Self-evaluation/img/sun.jpg) | 60070016 | Chaiyapong | Nithipeerawat | [@Sullvo1147](https://github.com/Sullvo1147) |
![](/Self-evaluation/img/max.jpg) | 60070018 | Thitikorn | Padungwatsawat | [@maxlunla](https://github.com/maxlunla) |
![](/Self-evaluation/img/print.jpg) | 60070034 | Thirada | Theethum | [@PrintTrd](https://github.com/PrintTrd) |

---

# ![](/Self-evaluation/img/assis_icon.png) Assistant Teacher
Assist.Prof. Dr. Kitsuchart Pasupa | Assist.Prof. Dr. Panwit Tuwanut
|:-:|:-:|
|![](/Self-evaluation/img/eacher_kritsuchart.jpg) | ![](/Self-evaluation/img/teacher_panwit.jpg)|

---

Computer Programming 2017

Faculty of Information Technology

King Mongkut's Institute of Technology Ladkrabang
