
////////////////////temp//////////////////////

#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

///////////////////servo///////////////////////

#include <Servo.h>
Servo myservo;  
int pos = 0;

void setup() {
  Serial.begin(9600); 
  Serial.println("Prasad MNT/20/15");
  dht.begin();
  myservo.attach(9);
}

void loop() {
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
