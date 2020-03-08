#include<AccelStepper.h>

const int step_pin=9;
const int dir_pin=10;
const int ms1=0;
const int ms2=0;
const int ms3=0; // driving in full step resolution 
             // this resolution can be and should be changed 


AccelStepper gen_stepper(1,step_pin,dir_pin);    

void setup() {
  gen_stepper.setMaxSpeed(100);
  gen_stepper.setSpeed(5);
  
}

void loop() {
  gen_stepper.runSpeed();
 
}

/*
 * long travel_x;
 * void setup()
 * {
 *  gen_stepper.setCurrentPosition(0);
 *  gen_stepper.setMaxAcceleration(1000);
 *  gen_stepper.setMaxSpeed(1000);
 *  ms1=0;
 *  ms2=0;
 *  ms3=0;
 *  Serial.begin(9600);
 *  }
 *  
 *  void loop()
 *  {
 *    travel_x=Serial.parseInt();
 *    gen_stepper.moveTo(travel_x);
 *    if(gen_stepper.distanceToGo()!=0)
 *    {
 *      gen_stepper.run();
 *    
 */
