int val_1 = 0;
double Time = 0.0;
//อย่าปรับความต้านทานของตัวสีฟ้า กว่าจะปรับได้ เหมือนจะขาดใจ

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);

}
void loop() {
val_1 = digitalRead(2);
Time = millis();
Serial.println(val_1);
//ตรวจเสียง ถ้ามีเสียง ให้ค่า 0 ไม่มีเสียงให้ค่า 1
//Serial.println(Time/1000);
//Serial.println("--------");
delay(10);

}

