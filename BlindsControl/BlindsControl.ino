/*
 * Arduino program that will move servo depending on button pressed
 */
 #include <Servo.h>
  
    const int buttonPin = 2;
    const int buttonPin2 = 4;
    int buttonState = 0;
    int buttonState2 = 0;
    Servo servoA;
    int position = 0;
  
  void setup() 
  {
    servoA.attach(9);
    Serial.begin(9600);  
    pinMode(buttonPin, INPUT);
    pinMode(buttonPin2,INPUT);
    //servoA.write(90);
    Serial.println("Application Starting...");
  }
  
  void loop() 
  {
  
      buttonState = digitalRead(buttonPin);   // right button 
      buttonState2 = digitalRead(buttonPin2); 
      
     if(buttonState2 == HIGH){
      //  servoA.write(position++);
      
   Serial.println("button state 1 HIGH");
       
     //   servoA.write(0); 
     //   delay(5); 
        
  }
  
    if(buttonState2 == LOW){
     //   servoA.write(position--);

     
    Serial.println("button state 1 LOW");
      
     //  servoA.write(170); 
    
    }
  
  }

