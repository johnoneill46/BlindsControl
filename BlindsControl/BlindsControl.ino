/*
 * Arduino program that will move servo depending on button pressed
 */
 #include <Servo.h>
  
    const int buttonPin = 2;
    const int servoPin = 9;
    Servo servo;
    int pos = 0;
    int buttonState = 0;         // current state of the button
    int lastButtonState = 0;     // previous state of the button

    int x = 0;
    int oldButtonState = LOW;
  
  void setup() 
  {
    
    servo.attach(servoPin);
    Serial.begin(9600);  
    pinMode(buttonPin, INPUT);
    servo.write(pos);
    Serial.println("Application Starting...");

  }
  
  void loop()
{ 
          // Get the current state of the button
      int newButtonState = digitalRead(buttonPin);
    
          // checks if button has changed since we last read it
      if (newButtonState == HIGH && oldButtonState == LOW) {
    
        if (x == 0) {
          // Toggle on
          openBlinds();
          x = 1;
    
        } else {
          // Toggle off
          closeBlinds();
          x = 0;
        }
        delay(50);
      }
    
      // Store the button's state so we can tell if it's changed next time round
      oldButtonState = newButtonState;

  }


  void openBlinds(){

       for(pos = 180; pos>=180; pos -=180)     // go from 180 degrees to 0 degrees 
       {                                
          servo.write(pos);
          Serial.println("Button Pressed - Opening Blinds");
          delay(20);
       } 
  }

  void closeBlinds(){

      for(pos = 0; pos<180; pos += 180)  // go from 0 degrees to 90 degrees 
         {
           servo.write(pos);
           Serial.println("Button Pressed - Closing Blinds");
           delay(20);
         } 
  }

