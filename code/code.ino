/* stepper motor control code for DRV8825
 * 
 */

 // define pin used
 const int stepPin = 9;
 const int dirPin = 8;
 const int control_pin=12;
 const int control_pinn=13;
 char stop_start='s';
 void setup() {
 // set the two pins as outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(control_pin,OUTPUT);
  pinMode(control_pinn,OUTPUT);
  Serial.begin(9600);
  digitalWrite(control_pin,LOW);
  digitalWrite(control_pinn,LOW);

}


void loop() {
digitalWrite(dirPin,HIGH); //Enables the motor to move in a perticular direction
// for one full rotation required 200 pulses

  


  digitalWrite(stepPin,HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin,LOW);
  delayMicroseconds(500);

  stop_start=Serial.read();
  if(stop_start=='1')
  {
    Serial.println("motor 1 starts...");
    digitalWrite(control_pin,HIGH);//enable the first motor 
    for(int x = 0; x < 200; x++){
      digitalWrite(stepPin,HIGH);//make it step
      delayMicroseconds(500);//later we will just make function and call it everywhere
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }
    digitalWrite(control_pin,LOW);
  }
  if(stop_start=='2')
  {
    Serial.println("motor 2 starts");
    digitalWrite(control_pinn,HIGH);
    for(int x=0;x<200;x++){
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);//later we will just make function and call it everywhere
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);      
    }
    digitalWrite(control_pinn,LOW);
  }

Serial.println("one cycle completes");


delay(1000); // delay for one second


}
