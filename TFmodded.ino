#define westButton 3 
#define eastButton 13
#define westRed 2
#define westYellow 5
#define westGreen 4
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define pedlight 7
#define pedbutton 8

#define yellowBlinkTime 500 // 0.5 seconds for yellow light blink

boolean trafficWest = true; // west = true, east = false
boolean trafficEast = false;
int flowTime = 2000;       // amount of time to let traffic flow
int changeDelay = 1000;     // amount of time between color changes


void setup() {
   Serial.begin(9600);
  // set up the digital I/O pins
   pinMode(westButton, INPUT);
   pinMode(eastButton, INPUT);
   pinMode(pedbutton, INPUT);
   pinMode(pedlight, OUTPUT);
   pinMode(westRed, OUTPUT);
   pinMode(westYellow, OUTPUT);
   pinMode(westGreen, OUTPUT);
   pinMode(eastRed, OUTPUT);
   pinMode(eastYellow, OUTPUT);
   pinMode(eastGreen, OUTPUT);
   // set initial state for lights - west side is green first
   digitalWrite(westRed, LOW);
   digitalWrite(westYellow, LOW);
   digitalWrite(westGreen, HIGH); 
   digitalWrite(eastRed, HIGH);
   digitalWrite(eastYellow, LOW);
   digitalWrite(eastGreen, LOW);
}

void loop() {
   if ( digitalRead(westButton) == HIGH ) // request west>east traffic flow
   {
      Serial.println("West Button");
    if ( trafficWest != true ) 
      // only continue if traffic flowing in the opposite (east) direction
      {
         Serial.println("Stop East Traffic");
    trafficWest = true; // change traffic flow flag to west>east
    delay(flowTime);    // give time for traffic to flow 
    digitalWrite(eastGreen, LOW); // change east-facing lights from green to yellow to red
    digitalWrite(eastYellow, HIGH);
    delay(changeDelay);
    digitalWrite(eastYellow, LOW);
    digitalWrite(eastRed, HIGH);
    delay(changeDelay); 
    for ( int a = 0; a < 5; a++ ) // blink yellow light
      {
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
        }
       digitalWrite(westYellow, LOW);
       digitalWrite(westRed, LOW); // change west-facing lights from red
                                   // to green
       digitalWrite(westGreen, HIGH); 
       Serial.println("Go West Traffic");
       }
}
 if ( digitalRead(eastButton) == HIGH ) // request east>west traffic flow
{
    Serial.println("East Button");
   if ( trafficEast == false ) // only continue if traffic flow is in the opposite (west) direction
   {
       Serial.println("Stop West Traffic");
      trafficEast =  ; // change traffic flow flag to east>west
      delay(flowTime);     // give time for traffic to flow 
      digitalWrite(westGreen, LOW); 
      // change west-facing lights from green to yellow to red
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay); 
      for ( int a = 0 ; a < 5 ; a++ ) // blink yellow light 
      {
         digitalWrite(eastYellow, LOW);
         delay(yellowBlinkTime);
         digitalWrite(eastYellow, HIGH);
         delay(yellowBlinkTime);
      } 
      digitalWrite(eastYellow, LOW); 
      digitalWrite(eastRed, LOW); // change east-facing lights from red
                                  // to green
      digitalWrite(eastGreen, HIGH); 
       Serial.println("Go East Traffic");
      }
   }
   if (digitalRead(pedbutton) == HIGH){
         trafficWest = false;
         trafficEast = false;
         Serial.println("PED LIGHT ON");
         digitalWrite(westGreen, LOW);
         digitalWrite(westYellow, LOW);
         digitalWrite(westRed, HIGH);
         digitalWrite(eastGreen, LOW);
         digitalWrite(eastYellow, LOW);
         digitalWrite(eastRed, HIGH);
         delay(5000);
         for ( int a = 0 ; a < 5 ; a++ ) // blink PED LIGHT
      {
         digitalWrite(eastYellow, HIGH);
         digitalWrite(westYellow, HIGH);
         delay(yellowBlinkTime);
         digitalWrite(eastYellow, LOW);
         digitalWrite(westYellow, LOW);
         delay(yellowBlinkTime);
         
      }
         for ( int a = 0 ; a < 5 ; a++ ) // blink PED LIGHT
      {
         digitalWrite(pedlight, LOW);
         delay(yellowBlinkTime);
         digitalWrite(pedlight, HIGH);
         delay(yellowBlinkTime);
      }
         digitalWrite(pedlight, LOW);
         Serial.println("PED LIGHT OFF");


   }  
}









