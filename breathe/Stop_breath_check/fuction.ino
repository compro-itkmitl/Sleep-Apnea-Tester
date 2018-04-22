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





int ReadText(){                                  // re-open the file for reading:
  int roundd=0;
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("--------           test.txt          --------");

    // read from the file until there's nothing else in it:
    while (myFile.available()){
      Serial.write(myFile.read());
      roundd++;
    }
    myFile.close();                              // close the file:
  } 
  else {
    Serial.println("error opening test.txt");  // if the file didn't open, print an error:
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
  Serial.print(timed);
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
  Serial.println(timed);
  return timed;
}



void WriteText(String txt){
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    myFile.println(txt);
    myFile.close();
    Serial.println("Save in file....Done!");
  } 
  else {
    Serial.println("error opening test.txt");  // if the file didn't open, print an error:
  }
}

//  if(check_file != 0){
//    Serial.println("Something in \"test.txt\" file. Do you want to delete it? y/n");
//        while (!Serial.available()) {
//                // read the incoming byte:
//                command = Serial.readString();
//                Serial.println(command);
//                if(command == "y"){
//                  Serial.println("Removing output.txt");
//                  SD.remove("test.txt");
//                  myFile = SD.open("test.txt");
//                  myFile.close();
//                  break;
//                }
//                else if(command == "n"){
//                  Serial.println("Keep data in file");
//                  myFile = SD.open("test.txt", FILE_WRITE);
//                  myFile.close();
//                  break;
//                }
//        }
//  }
