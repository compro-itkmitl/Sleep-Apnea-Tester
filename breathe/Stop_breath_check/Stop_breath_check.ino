#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


//อย่าปรับความต้านทานของตัวสีฟ้า กว่าจะปรับได้ เหมือนจะขาดใจ
//anyway this code can't use in real situation
String command;
int val = 0, i;
int check_in_out = 0;
unsigned long star_stop_breath;
File myFile;
tmElements_t tm;
String printt;
float time = 0.0, continue_breath;
int f=0;


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
        Serial.println("Something in \"output.txt\" file.");
        SD.remove("output.txt");
        Serial.println("Removing output.txt");
        myFile = SD.open("output.txt", FILE_WRITE);
      }
//      else{
//        myFile = SD.open("output.txt", FILE_WRITE);
//      }
//  if(check_file != 0){
//    Serial.println("Something in \"output.txt\" file. Do you want to delete it? y/n");
//        while (!Serial.available()) {
//                // read the incoming byte:
//                command = Serial.readString();
//                Serial.println(command);
//                if(command == "y"){
//                  Serial.println("Removing output.txt");
//                  SD.remove("output.txt");
//                  myFile = SD.open("output.txt");
//                  myFile.close();
//                  break;
//                }
//                else if(command == "n"){
//                  Serial.println("Keep data in file");
//                  myFile = SD.open("output.txt", FILE_WRITE);
//                  myFile.close();
//                  break;
//                }
//        }
//  }


//  myFile = SD.open("output.txt", FILE_WRITE);
}
void loop() {


  for(i=0; i<20; i++){               //  get input form voice detect for check breath
    val += digitalRead(2);
    delay(20);
  }




  if(val >= 17){                    //  check breath
    check_in_out++;
  }

  else{
    if(check_in_out>8){
      printt += post(star_stop_breath);
      Serial.println(printt);
      WriteText(printt);
    }

    check_in_out = 0;
    star_stop_breath = 0;
    //    Serial.print("out");
  }
 
  val = 0;




  if(check_in_out==8){           // check if don't breath out more than 4 sec(when check >8)
    printt = pre();
    star_stop_breath = millis()-1000;
  }

}



String print2digits(int number) {
  String timed = "";
  if (number >= 0 && number < 10) {
    timed+='0';
  }
  timed+=number;
  return timed;
}


void write_in_file_2digits(int number) {
  if (number >= 0 && number < 10) {
    myFile.write('0');
  }
  myFile.print(number);
}


int ReadText(){                                       // re-open the file for reading:
  int roundd=0;
  myFile = SD.open("output.txt");
  if (myFile) {
    Serial.println("--------           output.txt          --------");

    // read from the file until there's nothing else in it:
    while (myFile.available()){
      Serial.write(myFile.read());
      roundd++;
    }
    myFile.close();                                   // close the file:
  } 
  else {
    Serial.println("error opening output.txt");  // if the file didn't open, print an error:
  }
  Serial.println("-----------------------------------------------");
  return roundd;
}


String pre(){
  String timed = "";
  timed += "Stop breathing! ";
  if (RTC.read(tm)){
    timed += tm.Day;
    timed += "/";
    timed += tm.Month;
    timed += "/";
    timed += tmYearToCalendar(tm.Year);
    timed += " ";
    timed += print2digits(tm.Hour);
    timed+=":";
    timed+=print2digits(tm.Minute);
    timed+=":";
    timed+=print2digits(tm.Second-1);
    timed+=" - ";
  }
  return timed;
}
String post(int num){
  String timed = "";
  if (RTC.read(tm)){
        timed+=print2digits(tm.Hour);
        timed+=":";
        timed+=print2digits(tm.Minute);
        timed+=":";
        timed+=print2digits(tm.Second);
      }
  timed+=" (you Stop breath for ";
  continue_breath = millis() - num;
  timed+=continue_breath/1000;
  timed+="sec)";
  return timed;
}
void WriteText(String txt){
  myFile = SD.open("output.txt", FILE_WRITE);
  if (myFile) {
    myFile.println(txt);
    myFile.close();
  } 
  else {
    Serial.println("error opening output.txt");  // if the file didn't open, print an error:
  }
}

