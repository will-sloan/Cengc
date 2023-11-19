#include <AFMotor.h>

AF_DCMotor motor(4, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(3, MOTOR12_1KHZ); // create motor #4, 64KHz pwm

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("C-Eng C!");
  
  motor.setSpeed(255);     // set the speed to 200/255
  motor2.setSpeed(25);
}

void loop() {
  // // Wait a bit for the thing to be in place
  delay(5000);
  Serial.println("Lift the bin!");
  motor.run(FORWARD);
  // Wait until its at the top
  delay(200);

  // Wait at the top 
  Serial.println("At top, stop.");
  motor.run(RELEASE);
  // Wait for a few seconds for things to fall. 
  delay(3000);

  // Go back down.
  Serial.println("Going down.");
  motor.run(BACKWARD);
  delay(250);

  // Stop motor.
  Serial.println("Stop Motor.");
  motor.run(RELEASE);

  // Now we do the wheel.
  // Since this did not work, we commented it out. 
  // motor2.setSpeed(100);
  // motor2.run(FORWARD);
  // delay(1000);
  // motor2.setSpeed(65);
  // delay(1000);
  // Serial.println("Running wheel.");
  // motor2.run(FORWARD);
  delay(30000);
  
}