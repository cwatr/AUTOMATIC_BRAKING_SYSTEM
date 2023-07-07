#include <Servo.h>;
Servo myservo;
int trigPin = 7;  //Define the pins that you will work with
int echoPin = 8;
int pos = 0;
float Speed = 0.0343;  // Sound speed at cm/us
long duration, distance;
int ldrPin=A0;
int ldrValue = 0;
int led = 3;

void setup() {
 pinMode(led, OUTPUT);
   myservo.attach(5);
   
   pinMode(trigPin, OUTPUT);  //Define digital pin 7 as an output

   pinMode(echoPin, INPUT);   //Define digital pin 8 as an input
}

void loop() {
  // put your main code here, to run repeatedly:

 ldrValue = analogRead(ldrPin);

 if(ldrValue < 150)
 {
  
   digitalWrite(led,HIGH);
   delay(1000);
 }
 else{   
  digitalWrite(led,LOW);
 delay(0);
 }

 {   
   digitalWrite(trigPin, LOW);        // Make sure that the TRIG is deactivated

   delayMicroseconds(2);              // Make sure that the TRIG is in LOW

   digitalWrite(trigPin, HIGH);       // Activate the output pulse 
   delayMicroseconds(10);             // Wait for 10µs, the pulse remains active during this time

   digitalWrite(trigPin, LOW);        //Stop the pulse and wait for ECHO 

   duration = pulseIn(echoPin, HIGH) ; // pulseIn measures the time since the defined pin (echoPin) changes its status from low to high (from 0 to 1)

   distance = Speed* duration / 2;   //Divide by 2 because we want to have only the “go” time, not the “go and back” time
                                       // and divide by 29,1 because 1 is divided by the sound speed (1/SpeedSound) at cm/us

   if ( distance < 15){
      myservo.write(pos = 30);

   }
   else{       // otherwise
        myservo.write(pos = 0);
       
 }
}
}
