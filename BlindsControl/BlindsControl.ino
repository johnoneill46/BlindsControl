#include <Servo.h>
 
Servo servo;
const int buttonPin = 2;
const int servoPin = 9;
bool blindsOpen = false;
int pos = 0;
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button
int oldButtonState = LOW;
  
void setup(){
    servo.attach(servoPin);
    Serial.begin(9600);  
    pinMode(buttonPin, INPUT);
    servo.write(pos);
    Serial.println("Application Started.");
  }
  
void loop(){ 
    int newButtonState = digitalRead(buttonPin);    // Get current button state
    
    if (newButtonState == HIGH && oldButtonState == LOW) {        // checks if button has changed since last read
         if (blindsOpen){
              closeBlinds();
              blindsOpen = false;       
         }else{
              openBlinds();
              blindsOpen = true;
         }
      delay(50);
    }
    oldButtonState = newButtonState;    // Store the button's state so we can tell if it's changed next time round
 }

void openBlinds(){
     servo.write(90);
     Serial.println("Opening Blinds")
     delay(20);
}

void closeBlinds(){
     servo.write(0);    // set to 5 to accomodate for slight offset with servo
     Serial.println("Closing Blinds");
     delay(20);
}
