
void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(13,HIGH);
Serial.println("LED ON");
delay(2000);
digitalWrte(13,LOw);
Serial.println("LED OFF");
delay(2000);
}
