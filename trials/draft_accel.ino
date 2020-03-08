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
  
}

void loop()
{
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}
