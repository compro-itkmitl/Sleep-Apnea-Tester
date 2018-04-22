#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


//อย่าปรับความต้านทานของตัวสีฟ้า กว่าจะปรับได้ เหมือนจะขาดใจ
//anyway this code can't use in real situation
int val = 0, val_2;
int check_in_out = 0;
unsigned long star_stop_breath;
File myFile;
tmElements_t tm;
String printt;
float time = 0.0, continue_breath;


// change this to match your SD shield or module;
//     Arduino Ethernet shield: pin 4
//     Adafruit SD shields and modules: pin 10
//     Sparkfun SD shield: pin 8
const int chipSelect = 10;

void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(SS, OUTPUT);
  Serial.println("--------Breathing Check for Sleep Apnea--------");
  
  if (!SD.begin(chipSelect)) {
    Serial.println("--------  SD Card initialization failed! --------");
  }
  else{
    Serial.println("--------  SD Card initialization done. --------");
  }
  int check_file = ReadText();

      if(check_file != 0){
        Serial.println("Something in \"test.txt\" file.");
        SD.remove("testt.txt");
        Serial.println("Removing test.txt");
        myFile = SD.open("test.txt");
        myFile.close();
      }

        myFile = SD.open("test.txt", FILE_WRITE);




//  myFile = SD.open("test.txt", FILE_WRITE);
}
void loop() {


  for(int i=0; i<20; i++){               //  get input form voice detect for check breath
    val += digitalRead(2);
    val_2 += digitalRead(3);
    delay(20);
  }




  if((val >= 17) && val_2 >= 17){                    //  check breath
    check_in_out++;
  }

  else{
    if(check_in_out>8){
      printt += post(star_stop_breath);
      WriteText(printt);
    }

    check_in_out = 0;
    star_stop_breath = 0;
    //    Serial.print("out");
  }
 
  val = 0;
//  val_2 = 0;




  if(check_in_out==8){           // check if don't breath out more than 4 sec(when check >8)
    printt = pre();
    star_stop_breath = millis()-1000;
  }

}

