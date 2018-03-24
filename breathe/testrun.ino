
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

  if (count == 20) {

    int count_active = 0;
    
    for (int i=0; i<25;i++) {
      if (sign[i] > 300) {
        count_active++; 
      }
    }

    count = 0;
    trigger = false;
    if (count_active > 3) {
      Serial.println("Breathing out");
    } else {
      Serial.println("Breathing in");
    }
    
  }

}
