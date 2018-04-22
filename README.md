# Sleep Apnea Tester
&nbsp;&nbsp;&nbsp;&nbsp;Sleep Apnea Tester is a micro-controller project for Computer Programming 2017 with two main objectives are Sleep Apnea surveillance and report irregularity statistics while sleeping.
  
&nbsp;&nbsp;&nbsp;&nbsp;Presently, the problem in sleeping was increase and these problems can risk assessment in diseases. Sleep Apnea Tester can solve sleep problem by respiratory rate measure, snore check and others while sleeping with Sound Microphone Detection Module. The statistics will be saved and can be checking to signify irregularity while sleeping if the irregularity was found while sleeping, the user can consult with paramedic for protecting in long term.

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

---

# ![](/Self-evaluation/img/board_icon.png) Board Connection

![](/Self-evaluation/img/Board.png)

---

# ![](/Self-evaluation/img/step_icon.png) How to use

**Part I: Sleep Apnea Risk Test**
   --For check risk to be Sleep Apnea Syndrome apart from **"Sleep Apnea Measurement"**.--
 MINGW gcc Compiler : https://sourceforge.net/projects/tdm-gcc/
1. Download Adultandchild.c from Sleep-Apnea-Tester/Self-evaluation/Risk's Self-evaluation/Adultandchild.c 
2. Open the Command Prompt (CMD Commands) and Change Directory to this file then type **gcc Sleep Apnea Risk Test.c -o a.out** for compile the code. 
3. Type **.\a.out** on command for run the program.
4. Waiting for the program in running for a minute.
4. Let's do this Sleep Apnea Risk Test!

**Tips : Disable Avast CyberCapture Completelly**
   To completely turn off CyberCapture in your Avast antivirus 2016 follow these steps:
1. Open Avast user interface and go to settings.
2. In the 'General' tab (first item) uncheck 'Enable CyberCapture'
3. Confirm by clicking the 'OK' button
![](/Self-evaluation/img/Avast setting.png)

**Part II : Sleep Apnea Measurement**

---

# ![](/Self-evaluation/img/rsz_team-icon.png) Members
ID | First Name | Surname
--- | --- | ---
60070016 | Chaiyapong | Nithipeerawat
60070018 | Thitikorn | Padungwatsawat
60070034 | Thirada | Theethum

---

# ![](/Self-evaluation/img/assis_icon.png) Assistant Teacher
Assist.Prof. Dr. Kitsuchart Pasupa | Assist.Prof. Dr. Panwit Tuwanut
|:-:|:-:|
|![](/Self-evaluation/img/teacher_kitsuchart.png) | ![](/Self-evaluation/img/teacher_panwit.png)|

---

Faculty of Information Technology

King Mongkut's Institute of Technology Ladkrabang
