// the circuit for this application requires an LED connected to digital pin 0 (D0)

int ledGood = D0; // green
int ledMedium = D1; // yellow 
int ledBad = D2; //red 

int Trig_pin = 3;
 int   Echo_pin = 5;
  long  Time_out = 3000;

int sensorPin = A0;
int analogSensor = 0;

//const char good;

void setup() {
    Serial.begin(9600);
    pinMode(ledGood, OUTPUT);
    pinMode(ledMedium, OUTPUT);
    pinMode(ledBad, OUTPUT);

    pinMode(sensorPin, INPUT);
    
      pinMode(Trig_pin,OUTPUT);
   pinMode(Echo_pin,INPUT);

    // expose the function blinkLED and give it the string name "blink"
    // Particle.function("call_name", called_function);
  //  Particle.function("blink", blinkLED);
    Particle.variable("analog", analogSensor);
    Particle.function("check", readSensor);
    Serial.println("setup complete");
    
}

void loop() {  
    //USonicRange();
    Serial.print("presser "); 
  Serial.println(analogSensor); 
         analogSensor = analogRead(sensorPin);   
    delay(50);
    if(analogSensor > 0 && analogSensor < 300){
 digitalWrite(ledGood, HIGH);


    } else {
        digitalWrite(ledGood, LOW);
    }
    
    if (analogSensor > 300 && analogSensor < 1000) {
         digitalWrite(ledMedium, HIGH);
         //return 2;

    } else {
        digitalWrite(ledMedium, LOW);
    }
    
      if (analogSensor > 1000 && analogSensor < 2000) {
         digitalWrite(ledBad, HIGH);
         //return 3;

    } else {
        digitalWrite(ledBad, LOW);
    }
 
    
}

int readSensor(String analogPin){
  analogSensor = analogRead(sensorPin);   
    delay(50);
    if(analogSensor > 0 && analogSensor < 300){
    
return 1;
//Spark.publish(String "good");


    } else if (analogSensor > 300 && analogSensor < 1000) {
         
         return 2;

    } else if (analogSensor > 1000 && analogSensor < 2000) {
         
         return 3;

    }  else{

        return -1;
    }


}



long USonicRange()
{ 
    //Serial.print("begin ");
      digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  long duration = pulseIn(Echo_pin,HIGH);
  if ( duration == 0 ) {
  duration = Time_out; }
  duration = duration / 29 / 2;
  //Serial.print("usonic "); 
  //Serial.println(duration); 
  return duration;
}


  

    
    
    /*if (analogSensor <= 100){
         digitalWrite(ledMedium, HIGH);
        
    } else if (analogSensor <= 1000){
        
        digitalWrite(ledBad, HIGH);
    }
    
    else  {
        digitalWrite(ledGood, LOW);
        digitalWrite(ledMedium, LOW);
        digitalWrite(ledBad, LOW);
    }

}*/
    // nothing needed here
    // function are called from outside the loop
 



// this is the function being exposed and called remotely
/*int blinkLED(String blinks) {
    // it takes the incoming argument and checks to make sure it’s not empty 
    if (blinks != NULL) {
        // converts it to an integer
        int num = blinks.toInt();
        // and then calls the function that turns the LED on and off 
        // while passing the number of blinks as an argument
       goodGarbage(num);
        return 1;
    } else {
       return -1; 
    }
}*/

// this function turns the LED on and off

