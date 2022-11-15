
#define echoPin 2 
#define trigPin 3 

long duration;
float time=0,distance=0;
int temp=0;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}
void loop() {
  
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
