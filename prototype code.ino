
#include <AFMotor.h> //import your motor shield library
#define trigPin 12 // define the pins of your sensor
#define echoPin 13 
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_64KHZ);


void setup() {
  Serial.begin(9600); // begin serial communitication  
  Serial.println("Blind prototype!");
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  
}
 
void loop() {

   long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 25)/
 {   
  Serial.print ( distance);
  Serial.print ( " CM!");// print out the distance in centimeters.
motor1.setSpeed(255); 
  motor2.setSpeed (255);
  Serial.println (" closest");
    motor1.run(FORWARD);
    motor2.run (BACKWARD);

}
 if (distance >25  && distance<100 )
 {   
  Serial.print ( distance);
  Serial.print ( " CM!");// print out the distance in centimeters.
motor1.setSpeed(175); 
  motor2.setSpeed (175);
  Serial.println (" close 2");
    motor1.run(FORWARD);
    motor2.run (BACKWARD);

}
 if (distance > 100 && distancw<200)
 {   
  Serial.print ( distance);
  Serial.print ( " CM!");// print out the distance in centimeters.
motor1.setSpeed(125); 
  motor2.setSpeed (125);
  Serial.println (" close 3");
    motor1.run(FORWARD);
    motor2.run (BACKWARD);

}
 if (distance >200)
 {   
  Serial.print ( distance);
  Serial.print ( " CM!");// print out the distance in centimeters.
motor1.setSpeed(55);
  motor2.setSpeed (55);
  Serial.println (" close 4");
    motor1.run(FORWARD);
    motor2.run (BACKWARD);

}
  else {
   Serial.println ("No detections");
   delay (15);
   motor1.setSpeed(0); 
   motor2.setSpeed(0);
  }  
}
  
  
