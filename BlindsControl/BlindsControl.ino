/*
 * Arduino program that will move servo depending on button pressed
 */
 #include <Servo.h>
  
    const int buttonPin = 2;
    const int buttonPin2 = 4;
    const int servoPin = 9;
    int rightButton;
    Servo servoA;
    int pos = 0;
    bool buttonBool = false;
    bool active = false;   // to be used to know if should be open or closed
  
  void setup() 
  {
    servoA.attach(servoPin);
    Serial.begin(9600);  
    pinMode(buttonPin, INPUT);
    Serial.println("Application Starting...");
  }
  
  void loop()
{ 
     
    if (digitalRead(buttonPin) == LOW){     // Button NOT pressed

       closeBlinds();
    }
     
     if (digitalRead(buttonPin) == HIGH) {     //Button Pressed

        openBlinds();
      
     }






  }


  void checkForButtonChange(){
      if(buttonBool = true){
        //button pressed to open
        openBlinds();
      }
      else{
        //button pressed to close
        closeBlinds();
      }
  }

  void openBlinds(){

       for(pos = 180; pos>=180; pos -=180)     // go from 90 degrees to 0 degrees 
       {                                
          servoA.write(pos);
          Serial.println("Button Pressed - Opening Blinds");
       delay(1000);
       } 
  }

  void closeBlinds(){

      for(pos = 0; pos<90; pos += 90)  // go from 0 degrees to 90 degrees 
         {
           servoA.write(pos);
         } 
  }

