int input=0;

int ms0=5;
int ms1=6;
int ms2=7;
int const enable1=10; // enable pin(made from  reset and sleep) for motor one. 
int const enable2=11; // for motor 2
int const enable3=12;
int const enable4=13;
int const enable5=4;

int enable={10,11,12,13,14,4};
AccelStepper stepper(1,9,8);
void setup() {
  stepper.setMaxSpeed(10000);
  stepper.setAcceleration(100000);
  
  digitalWrite(enable,HIGH);
  digitalWrite(ms0,HIGH);// this closer to enable on DRV825
  digitalWrite(ms1,HIGH);
  digitalWrite(ms2,HIGH);
  // all motor disabled
  for(int i=0;i<5;i++)
  {
    digitalWrite(enable[i],LOW);
  }
  // starting serial monitor
  Serial.begin(9600); 
  
}

void dispense(int motor)
{
  digitalWrite(enable[motor-1],HIGH);// enable just the current motor
  stepper.moveTo(3200); // 
  Serial.print("Running motor...");
  Serial.println(motor);
  while(stepper.distanceToGo() != 0)
  {
    stepper.run(); // take one revolution
  }
  stepper.setCurrentPosition(0); // set current state to zero; this is done so that for other motors the initial state of the stepper object is always 0 when the method starts to execute
  digitalWrite(enable[motor-1],LOW); // disable the motor again
}


void loop() {
  input=Serial.read();
  switch(input)
  {
    case 1://for first motor from left 
            dispense(1);
            break;

    case 2:
            dispense(2);
            break;

    case 3:
            dispense(3);
            break;
            

    case 4:
            dispense(4);
            break;

    case 5:
            dispense(5);
            break;
  }
  

}
