#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


//อย่าปรับความต้านทานของตัวสีฟ้า กว่าจะปรับได้ เหมือนจะขาดใจ
//anyway this code can't use in real situation
char command;
int val = 0, i;
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
  pinMode(SS, OUTPUT);
  Serial.println("--------Breathing Check for Sleep Apnea--------");
  
  if (!SD.begin(chipSelect)) {
    Serial.println("--------  SD Card initialization failed! --------");
  }
  else{
    Serial.println("--------  SD Card initialization done. --------");
  }
  int check_file = ReadText();
//  if(check_file != 0){
//    Serial.println("Something in \"output.txt\" file.");
//    SD.remove("output.txt");
//    Serial.println("Removing output.txt");
//    myFile = SD.open("output.txt");
//    myFile.close();
//  }
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
      printt += post(star_stop_breath);
      Serial.println(printt);
      WriteText(printt);
    }

    check_in_out = 0;
    star_stop_breath = 0;
    //    Serial.print("out");
  }
 
  val = 0;



// check if don't breath out more than 4 sec(when check >8)
  if(check_in_out==8){
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
int ReadText(){
  // re-open the file for reading:
  int roundd=0;
  myFile = SD.open("output.txt");
  if (myFile) {
    Serial.println("--------           output.txt          --------");

    // read from the file until there's nothing else in it:
    while (myFile.available()){
      Serial.write(myFile.read());
      roundd++;
    }
    // close the file:
    myFile.close();
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening output.txt");
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
    timed+=tm.Minute;
    timed+=":";
    timed+=tm.Second-1;
    timed+=" - ";
  }
  return timed;
}
String post(int num){
  String timed = "";
  if (RTC.read(tm)){
        timed+=tm.Hour;
        timed+=":";
        timed+=tm.Minute;
        timed+=":";
        timed+=tm.Second;
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
    // if the file didn't open, print an error:
    Serial.println("error opening output.txt");
  }
}

