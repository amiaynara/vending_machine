// Bounce.pde
// -*- mode: C++ -*-
//
// Make a single stepper bounce from one limit to another
//
// Copyright (C) 2012 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

int ms0=5;
int ms1=6;
int ms2=7;
int n=100; // this number will never be reached
int N=10; // edit this to change the number of steppers present in the machine
int stepper_array[N];
int enable=10;
#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1,9,8); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(10000);
  stepper.setAcceleration(100000);
  stepper.moveTo(3200);//at 16 of the microstepping we need 3200 steps for 1 revolution
  digitalWrite(enable,HIGH);
  digitalWrite(ms0,HIGH);
  digitalWrite(ms1,HIGH);
  digitalWrite(ms2,HIGH);
  //initialise the stepper array; note that this could be made two dimensional for better representation of the problem
  for(int i=0;i<N;i++)
  {
    stepper_array[i]=i+1;
  } 
  
}

//runs the stepper
void run_stepper(int stepper_number)
{
  //enable nth stepper 
  digitalWrite(stepper_array[stepper_number],HIGH);
  while(True)    // If at the end of travel go to the other end
  {
    if(stepper.distanceToGo()==0)
    {
      stepper.moveTo(-stepper.currentPosition());
      // break; // you will need to break once rotation is complete; you will need to find that TRIGGER 
    }
    stepper.run();
  }
}

void loop()
{

  n=Serial.read();
  run_stepper(n);
}
