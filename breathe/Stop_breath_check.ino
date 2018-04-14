
//อย่าปรับความต้านทานของตัวสีฟ้า กว่าจะปรับได้ เหมือนจะขาดใจ
//ใช้ได้ในเวลาสั้นๆ หานใช้นานค่าระยะเวลาที่หยุดหายใจจะเพี้ยน
//in cast with normal breathing
//anyway this code can't use in real situation
int val = 0, i;
int check_in_out = 0;
int star_stop_breath;

float time = 0.0, continue_breath;
void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT);

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
      Serial.println("Breath again");
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
      star_stop_breath = millis()+1000;
    }
  }
  Serial.println(millis());
}
