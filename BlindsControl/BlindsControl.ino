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
     // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {

      if (buttonState == HIGH) {    // if current state is HIGH then button went from off to on:
        Serial.println("On");
        openBlinds();
      } else {                      // if current state is LOW then the button went from on to off:
        Serial.println("Off");
        closeBlinds();
      }
      // Delay a little bit to avoid bouncing
      delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;

   

  }


  void openBlinds(){

       for(pos = 180; pos>=180; pos -=180)     // go from 180 degrees to 0 degrees 
       {                                
          servo.write(pos);
          Serial.println("Button Pressed - Opening Blinds");
          delay(2000);
       } 
  }

  void closeBlinds(){

      for(pos = 0; pos<180; pos += 180)  // go from 0 degrees to 90 degrees 
         {
           servo.write(pos);
         } 
  }

