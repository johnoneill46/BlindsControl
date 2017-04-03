/*
 * Arduino program that will move servo depending on button pressed


 TODO:
 - extend servo arms to increase pullable distance
 - Connect to internet
 - Call servo change via internet call?
 - Alexa app to control
 
 */
 
 #include <Servo.h>
  
    const int buttonPin = 2;
    const int servoPin = 9;
    Servo servo;
    
    int pos = 0;
    int buttonState = 0;         // current state of the button
    int lastButtonState = 0;     // previous state of the button
    int oldButtonState = LOW;
    bool blindsOpen = false;
  
  void setup(){
    
    servo.attach(servoPin);
    Serial.begin(9600);  
    pinMode(buttonPin, INPUT);
    servo.write(pos);
    Serial.println("Application Started.");
  }
  
   void loop(){ 
            
           // Get the current state of the button
        int newButtonState = digitalRead(buttonPin);
      
           // checks if button has changed since we last read it
        if (newButtonState == HIGH && oldButtonState == LOW) {
          
              if (!blindsOpen){
                  openBlinds();
                  blindsOpen = true;
          
               } else{
                  closeBlinds();
                  blindsOpen = false;
              }
                 delay(50);
        }
      
        // Store the button's state so we can tell if it's changed next time round
        oldButtonState = newButtonState;
   }


  void openBlinds(){
                               
          servo.write(90);
          Serial.println("Opening Blinds");
          delay(20);
  }

  void closeBlinds(){
    
           servo.write(0);  // set to 5 to accomodate for slight offset with servo
           Serial.println("Closing Blinds");
           delay(20);
  }

