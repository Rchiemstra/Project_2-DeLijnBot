uint32_t timer ;

int afstandgebrokenlijn = 1500;
uint32_t gebrokenlijn = afstandgebrokenlijn;

int afstandrondje = 1800;
uint32_t rondje = afstandrondje;

#include <NewPing.h>
#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//Ping-Sensor
const int trig = 10;  //Stuurt ping weg
const int echo = 11;  //Ontvangt ping

//IR-Sensoren
const int ir1 = 6;
const int ir2 = 7;
const int ir3 = 8;
const int ir4 = 9;

//Motor(H-Brug)
const int motorLinksPin1  = 2;  // Pin 14 of L293,  Vooruit
const int motorLinksPin2  = 3;  // Pin 10 of L293,  Achteruit
const int motorRechtsPin1  = 4;  // Pin  7 of L293, Vooruit
const int motorRechtsPin2  = 5;  // Pin  2 of L293, Achteruit

void setup() {

  //initial start time
  

  //IR-Sensoren
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);

  //Ping-Sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  //Motor(H-Brug)
  pinMode(motorLinksPin1, OUTPUT);  //+vooruit
  pinMode(motorLinksPin2, OUTPUT);  //+achteruit
  pinMode(motorRechtsPin1, OUTPUT); //+vooruit
  pinMode(motorRechtsPin2, OUTPUT); //+achteruit
  Serial.begin(2000000);

}

void loop() {
  timer = millis();
  Serial.println(timer);

  int IRstatus = IRdetect();
  Serial.println(IRstatus);
  delay(10);

    while (sonar.ping_cm() < 8) { //UltrasoneSensor detect stop
      Serial.println("Obstacle detected: STOP");
      digitalWrite(motorLinksPin1, LOW);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, LOW);
      digitalWrite(motorRechtsPin2, LOW);
    }
  
  switch (IRstatus) {
    case 15:              //Sensor 1,2,3,4
      Serial.println("Case 15:  Rechtdoor");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.print("gebrokenlijn ");
      Serial.println(gebrokenlijn);
      break;

    case 14:              //Sensor 1,2,3
      Serial.println("Case 14:  Linksaf");
      digitalWrite(motorLinksPin1, LOW);
      digitalWrite(motorLinksPin2, HIGH);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 13:              //Sensor 1,2,4
      Serial.println("Case 13:  Nog te bepalen");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 12:              //Sensor 1,2
      Serial.println("Case 12:  Linksaf ");
      digitalWrite(motorLinksPin1, LOW);
      digitalWrite(motorLinksPin2, HIGH);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 11:             //Sensor 1,3,4
      Serial.println("Case 11:  Nog te bepalen");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 10:             //Sensor 1,3
      Serial.println("Case 10:  Nog te bepalen");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 9:              //Sensor 1,4
      Serial.println("Case 9:  Nog te bepalen");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 8:              //Sensor 1
      Serial.println("Case 8:  Nog te bepalen");
      digitalWrite(motorLinksPin1, LOW);
      digitalWrite(motorLinksPin2, HIGH);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 7:              //Sensor 2,3,4
      Serial.println("Case 7:  Rechtsaf");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, LOW);
      digitalWrite(motorRechtsPin2, HIGH);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 6:              //Sensor 2,3
      Serial.println("Case 6:  Rechtdoor");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 5:              //Sensor 2,4
      Serial.println("Case 5:  Nog te bepalen");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;


    case 4:              //Sensor 2
      Serial.println("Case 4:  Correctie Links");
      digitalWrite(motorLinksPin1, LOW);
      digitalWrite(motorLinksPin2, HIGH);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 3:              //Sensor 3,4
      Serial.println("Case 3:  Rechtsaf");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, LOW);
      digitalWrite(motorRechtsPin2, HIGH);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 2:              //Sensor 3
      Serial.println("Case 2:  Correctie Rechts");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, LOW);
      digitalWrite(motorRechtsPin2, HIGH);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 1:              //Sensor 4
      Serial.println("Case 1:  Rechtsaf");
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, LOW);
      digitalWrite(motorRechtsPin2, HIGH);
      gebrokenlijn = afstandgebrokenlijn + timer;
      Serial.println(gebrokenlijn);
      break;

    case 0:              //Sensor

      Serial.println("Case 0:  EndLine");

      Serial.println(gebrokenlijn);
      digitalWrite(motorLinksPin1, HIGH);
      digitalWrite(motorLinksPin2, LOW);
      digitalWrite(motorRechtsPin1, HIGH);
      digitalWrite(motorRechtsPin2, LOW);

      if (gebrokenlijn <= timer) {
        rondje = timer + afstandrondje;
        while (rondje >= timer) {
          timer = millis();
          digitalWrite(motorLinksPin1, HIGH);
          digitalWrite(motorLinksPin2, LOW);
          digitalWrite(motorRechtsPin1, LOW);
          digitalWrite(motorRechtsPin2, HIGH);
          
        }
        gebrokenlijn = afstandgebrokenlijn + timer;
      }



      break;

  }
}

//functie die een code opstelt dmv input ir sensoren.
int IRdetect() {
  int  irdata = B0000;
  irdata += B1000 * digitalRead (ir1);
  irdata += B100 * digitalRead (ir2);
  irdata += B10 * digitalRead (ir3);
  irdata += B1 * digitalRead (ir4);
  return irdata;
}
