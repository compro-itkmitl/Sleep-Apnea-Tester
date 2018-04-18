#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


//อย่าปรับความต้านทานของตัวสีฟ้า กว่าจะปรับได้ เหมือนจะขาดใจ
//in cast with normal breathing
//anyway this code can't use in real situation
int val = 0, i;
int check_in_out = 0;
unsigned long star_stop_breath;
File myFile;
tmElements_t tm;

// change this to match your SD shield or module;
//     Arduino Ethernet shield: pin 4
//     Adafruit SD shields and modules: pin 10
//     Sparkfun SD shield: pin 8
const int chipSelect = 10;

float time = 0.0, continue_breath;
void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT);
  pinMode(SS, OUTPUT);

  
  if (!SD.begin(chipSelect)) {
    Serial.println("SD Card initialization failed!");
  }
  else{
    Serial.println("SD Card initialization done.");
  }
  myFile = SD.open("output.txt", FILE_WRITE);

}
void loop() {



//  get input form voice detect for check breath
  for(i=0; i<20; i++){
    val += digitalRead(2);
    delay(20);
  }



//  check breath
  if(val >= 17){
    check_in_out++;
    //    Serial.print("in");
  }

  else{
    if(check_in_out>8){
      if (RTC.read(tm)){
        print2digits(tm.Hour);
        Serial.write(':');
        print2digits(tm.Minute);
        Serial.write(':');
        print2digits(tm.Second);
        Serial.println();

      }
      Serial.print("you Stop breath for");
      continue_breath = millis() - star_stop_breath;
      Serial.print(continue_breath/1000);
      Serial.println("sec");
    }
    check_in_out = 0;
    star_stop_breath = 0;
    //    Serial.print("out");
  }
 
  val = 0;



// check if don't breath out more than 4 sec(when check >8)
  if(check_in_out>=8){
    if(check_in_out==8){
      Serial.println("Stop breathing!!!!");
      if (RTC.read(tm)){
        Serial.print("Date = ");
        Serial.print(tm.Day);
        Serial.write('/');
        Serial.print(tm.Month);
        Serial.write('/');
        Serial.print(tmYearToCalendar(tm.Year));
        Serial.write(' ');
        print2digits(tm.Hour);
        Serial.write(':');
        print2digits(tm.Minute);
        Serial.write(':');
        print2digits(tm.Second-1);
        Serial.print(" - ");


      }
      star_stop_breath = millis()-1000;
    }
  }
}



void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
void write_in_file_2digits(int number) {
  if (number >= 0 && number < 10) {
    myFile.write('0');
  }
  myFile.print(number);
}
