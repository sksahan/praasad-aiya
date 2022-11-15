
//////////////ultrasonic/////////////
#define echoPin 2 
#define trigPin 3 

long duration;
float time=0,distance=0;
int temp=0;

//////////////temp///////////////
#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

///////////////////servo///////////////////////

#include <Servo.h>
Servo myservo;  
int pos = 0;



void setup() {

//////////////////ultrasonic void setup //////////////////
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");

///////////////////temp void setup ////////////////////

  Serial.begin(9600); 
  Serial.println("Prasad MNT/20/15");
  dht.begin();
  myservo.attach(9);

}

void loop() {
     ultrasonic();
     temperature();

}

void ultrasonic (void) 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
   delay(100);

  if (distance <= 5 && temp==0 ) {
    digitalWrite (13,LOW);
    delay(100);
    temp==1;
  }

   else if (distance <= 5 && temp==1) {
    digitalWrite (13,LOW);
    delay(100);
  }

   else if (distance > 15 ) {
    digitalWrite (13,HIGH);
    delay(100);
    temp==0;
  }

  
}

void temperature (void)
{
  delay(1000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hi = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");


 if (t <= 29) {

       myservo.write(0);
       delay(15);

     }

   else if (f <= 92) {
     
      myservo.write(30);
      delay(15);

                    
  }

  else if (f <= 93.23) {
     
      myservo.write(60);
      delay(15);

                    
  }

  else if (f <= 94) {
     
      myservo.write(90);
      delay(15);

                    
  }

  else {
       myservo.write(0);
      delay(15);
  }
  
}
