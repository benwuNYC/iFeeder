/************************************************************************************************************
  TITLE:          iFeeder Automatic Pet Food Dispenser
  Created by:     Hansen Li, Benjamin Wu, Kevin Wu
  DATE:   11/24/2019

  Description:
    Electronic Components:
      - 3 DC motors
      - 1 Ultrasonic Sensor
      - 1 Arduino Uno
      - Breadboard
      - Connecting Wires
      - Resistors
      
iFeeder 
Inspired by starving pets in Venezuela
Food, snack, water dispenser
Personalized feeding schedule
Customizable meal portions 
User friendly schedule setup 

***************************************************************************************************************/
int motorPin = 7; 
int motorPin2 = 3;
int motorPin3 = 11;
#define trigger 9 //for Ultrasonic sensor 
#define echo 8 //for Ultrasonic sensor 
float time=0, distance=0;

/*
* setup() - this function runs once when you turn your Arduino on
* Defines which pins are INPUT or OUTPUT 
*/

void setup()
{
pinMode(motorPin, OUTPUT); 
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(trigger,OUTPUT); 
pinMode(echo,INPUT);
}

/*
* loop() - this function will start after setup finishes and then repeat
* Input: User expected to run program at exactly 9:00 AM 
* Refills water after every meal if needed 
*/

void loop() {
 food_motor() ; //Breakfast at 9:00 AM
 water_motor();
 delay(7200000);
 snack_motor(); //Snack at 11:00 AM 
 water_motor();
 delay(5400000); 
 food_motor(); //Lunch at 12:30 PM
 water_motor(); 
 delay(12600000); 
 snack_motor(); //Snack at 4:00 PM
 water_motor();
 delay(14400000); 
 food_motor(); //Dinner at 8:00 PM
 water_motor();
 delay(39600000); 
}

/*
 * food_motor() - this function will dispense the food at 9:00 AM, 12:30 PM, 8:00 PM
 * Turns on DC motor for 10 seconds and turns off to dispense food 
 */
 
void food_motor(){ 
  int onTime = 10000; 
  digitalWrite(motorPin, HIGH); 
  delay(onTime); 
  digitalWrite(motorPin, LOW);  
}

/*
 * snack_motor() - this function will dispense the snacks at 11:00 AM, 4:00 PM 
 * Turns on DC motor for 10 seconds and turns off to dispense food 
 */
 
void snack_motor(){ 
  int onTime = 10000; 
  digitalWrite(motorPin2, HIGH); 
  delay(onTime); 
  digitalWrite(motorPin2, LOW);
}

/*
 * measure_distance() - this function measures distance of dispenser tray and ultrasonic sensor 
 */
 
void measure_distance()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time = pulseIn(echo,HIGH);
 distance=time*340/20000;
}

/*
 * water_motor() - this function dispenses water depending on how much water is left in the tray  
 * If distance of water to sensor is less than 30 cm, water dispensed for 5 seconds 
 * Delay 0.5 seconds to avoid bouncing 
 */
 
void water_motor(){ 
 measure_distance();
 if(distance < 30){
  digitalWrite(motorPin3, HIGH);
  delay(5000);
 }else{
   digitalWrite(motorPin3, LOW);
 }
 delay(500); 
}
