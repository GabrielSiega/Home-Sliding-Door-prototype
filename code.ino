//Home Sliding Garage Door Project//
//**OWNER:GABRIEL SIEGA IGNATIUS MARIE ARANETA SIEGA**//
//**LAST UPDATED 3/24/22**//

//#define BLYNK_PRINT Serial
//#include<DHT.h>
//#include<WiFi.h>
//#include <WiFiClient.h>
//#include <BlynkSimpleEsp32.h>



//#define trigPin1 A1  // Define [Trigger]Analog pin for HC-SR04 (Closed door Position)//
//#define echoPin1 A0  // Define [Echo]Analog pin for HC-SR04 (Closed doore Position)//
//#define trigPin2 A3  // Define [Trigger]Analog pin for HC-SR04 (Near Motor Position)//
//#define echoPin2 A2  // Define [Echo]Analog pin for HC-SR04 (Near Motor Position) //

const int trigPin1 = A2; // Define [Trigger]Analog pin for HC-SR04 (Closed door Position)//
const int echoPin1 = A4; // Define [Echo]Analog pin for HC-SR04 (Closed doore Position)//
const int trigPin2 = A3; // Define [Trigger]Analog pin for HC-SR04 (Near Motor Position)//
const int echoPin2 = A5; // Define [Echo]Analog pin for HC-SR04 (Near Motor Position) //

const int sensorPin = A1;  //TMP Pin

int Alarm1 = 5; //Initialise PWM pin for Alarm1
int Alarm2 = 6; //Initialise PWN pin for Alarm2



int Redled1 = 9; // the PWM pin the LED is attached to
int Redled2 = 10; // the PWM pin the LED is attached to
int Redled3 = 11; // the PWM pin the LED is attached to
int Orangeled1 = 12; // the PWM pin the LED is attached to
int Redled5 = 13; // the PWM pin the LED is attached to
int Redled6 = 8; // the PWM pin the LED is attached to



int SensorValue = 0;
int LedWhite = 7;           //Temperature led

const float baselineTemp = 24.0; 


int brightness = 0; // how bright the LED is
int fadeAmount = 5; // how many points to fade the LED by
// the setup routine runs once when you press reset:




//long duration, distance, FIRSTSensor,SECONDSensor,THIRDSensor;
long duration, distance, duration1, distance1;
void setup() {
   
  
  
Serial.begin (9600); 
  
  
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
  
    
  
  // declare pin 9 to be an output:
   pinMode(Redled1, OUTPUT);
   // declare pin 10 to be an output:
   pinMode(Redled2, OUTPUT);
   // declare pin 11 to be an output:
   pinMode(Redled3, OUTPUT);
   //* declare pin 12 to be an output:
   pinMode(Orangeled1, OUTPUT);
   // declare pin 13 to be an output:
   pinMode(Redled5, OUTPUT);
   // declare pin 8 to be an output:
   pinMode(Redled6, OUTPUT);
  
  
  
  
pinMode(Alarm1, OUTPUT);   //declare ALARM1 as an output:
pinMode(Alarm2, OUTPUT);   //declare ALARM2 as an output:
digitalWrite(Alarm1, LOW);
digitalWrite(Alarm2, LOW); 
  
  
}

// the loop routine runs over and over again forever:

void loop() {
   
  digitalWrite(trigPin1, LOW);
  delayMicroseconds (2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1=duration1*0.034/2;
  Serial.print(" Distance1:");
  Serial.print(distance1);

  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds (2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds (10);
  digitalWrite(trigPin2, LOW);// Reads the echopin, returns the sound wave travel time in microseconds
  duration=pulseIn(echoPin2,HIGH);//calculating the distance
  distance=duration*0.034/2;//Prints the distance on the Serial Monitor
  Serial.print(" Distance:");
  Serial.print(distance);

  
  
  
//SonarSensor(trigPin1, echoPin1);
//FIRSTSensor = distance;
//SonarSensor(trigPin2, echoPin2);
//SECONDSensor = distance;
  
/////////////////////////////////////////////////////////////
digitalWrite(Alarm1, LOW);
digitalWrite(Alarm2, LOW);  
//////////////////////////  
//**DISCARDED**//
  //Serial.print("S1:");Serial.println(FIRSTSensor); //Serial Monitor Print [Distance from 1st HCSR.]:
//delayMicroseconds(10000);
//Serial.print("S2:");Serial.println(SECONDSensor); //Serial Monitor Print [Distance from 2nd HCSR.]:
//delayMicroseconds(10000);  
//////////////////////////  
  
  
  int sensorVal = analogRead(sensorPin); 
  float voltage = (sensorVal / 1024.0) * 5.0; 
  float temperature = (voltage - .5) * 100; 

     //Serial Monitor Printing
  Serial.print(" Temperature:");
  Serial.println(temperature); 
  
  
  // set the brightness of pin 9:
   analogWrite(Redled1, brightness);
   // set the brightness of pin 10:
   analogWrite(Redled2, brightness);
  // set the brightness of pin 11:
   analogWrite(Redled3, brightness);
  //* set the brightness of pin 12:
  //* analogWrite(Orangeled1, brightness);
  // set the brightness of pin 13:
   analogWrite(Redled5, brightness);
  // set the brightness of pin 8:
   analogWrite(Redled6, brightness);
  
  
  
  
  
   // change the brightness for next time through the loop:
   brightness = brightness + fadeAmount;
   // reverse the direction of the fading at the ends of the fade:
   if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
   }
  
  
   // wait for 9 milliseconds to see the dimming effect
   delay(90);
  
  
  
  if (temperature > baselineTemp)   //TMP
{ 
 digitalWrite(LedWhite, HIGH); 
  delay(50); 
} 
else 
{ 
digitalWrite(LedWhite, LOW); 
  delay(50);
}
 
  
  
   delay(1000);
  if (distance1 <= 4){
   // Blynk.notify("The bin is FULL!"); 
    digitalWrite(Orangeled1,HIGH);                       //Green Led
  //  lcd.clear();
  //  lcd.print(0,0, "The Bin is Full");
    delay(1000);
   }
   else{
    digitalWrite(Orangeled1,LOW);
    delay(1000);
   } 
  
  
//void SonarSensor(int trigPin,int echoPin);
//{
//digitalWrite(trigPin, LOW);
//delayMicroseconds(2);
//digitalWrite(trigPin, HIGH);
//delayMicroseconds(10);
//digitalWrite(trigPin, LOW);
//duration = pulseIn(echoPin, HIGH);
//distance = (duration/2) / 29.1;
//}  

  
  
}
