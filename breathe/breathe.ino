
int sign[20];
int count = 0;
boolean trigger = false;

void setup() {

  Serial.begin(115200);
  pinMode(A0, INPUT);

}

void loop() {

//  Serial.println(analogRead(A0));

  if (analogRead(A0) > 300 || trigger == true) {
    trigger = true;
    if (count == 0) {
      Serial.print("Triggered! : ");
    }
    sign[count] = analogRead(A0);
    count++;
  }

  

}
