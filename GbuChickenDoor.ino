#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
//#include <SimpleTimer.h>
Servo servo;
char auth[] = "vdj69A4n3GgkDRONFsVK3xzMmKLem0b*";
char ssid[] = "Ferma";
char pass[] = "8916592136*";
int relay1 = 5;//D1
int relay2 = 4;//D2
int relayVButton1 = 0;
int relayVButton2 = 0;
int relayVButton3 = 0;
boolean relayState1 = 1;
boolean relayState2 = 1;
boolean relayState3 = 1;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
}

void somefunction()  {
  if ( relayVButton1 > 0 && (relayState2=1)) {
    relayState1 = !relayState1;
  }
  digitalWrite(relay1, relayState1);
  //digitalWrite(relay1, LOW);
  //digitalWrite(relay2, LOW);

  if ( relayVButton2 > 0 && (relayState1=1)) {
    
    relayState2 = !relayState2;
  }
  digitalWrite(relay2, relayState2);

  if ( relayVButton3 > 0) {
    
   digitalWrite(relay2, HIGH);
   digitalWrite(relay1, HIGH);
  }
  

  
  }
  BLYNK_WRITE(V10)
  {
    // Get the state of the VButton
    relayVButton1 = param.asInt();
  }

  BLYNK_WRITE(V11)
  {
    // Get the state of the VButton
    relayVButton2 = param.asInt();
  }

  BLYNK_WRITE(V12)
  {
    relayVButton2 = param.asInt();
  }
  
void loop() {
  Blynk.run();
  somefunction();
}
