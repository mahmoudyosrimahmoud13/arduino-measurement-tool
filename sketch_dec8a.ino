#include <SoftwareSerial.h>

#include <NewPing.h>
//bluetooth
SoftwareSerial myserial (6,7); //rx6,tx7
//ultra sonic
#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 600
//buttons and buzzer 
#define btn_1 2
#define btn_2 3
#define buzzer 8
//leds
#define hieght 9
#define width 10
String status = "'Hight'";
String str_distance = "";
int count = 0,distance=0;
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
  //leds
  pinMode(hieght, OUTPUT);
  pinMode(width, OUTPUT);
  
  pinMode(btn_1,INPUT_PULLUP);
  pinMode(btn_2,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  myserial.begin(9600);
  Serial.begin(9600);
  digitalWrite(hieght, LOW);
  digitalWrite(width,  LOW);
}

void loop() {
  distance = sonar.ping_cm();
  
  if(digitalRead(btn_1)==LOW){
      delay(10);
      count=1;
      digitalWrite(buzzer, HIGH);
      digitalWrite(hieght, HIGH);
      digitalWrite(width, LOW);
      delay(250);
      digitalWrite(buzzer,LOW);
    str_distance = String(distance);
    status = str_distance + "/hieght";
    myserial.println(status);
    Serial.println(status);
    }
    if (digitalRead(btn_2)==LOW) {
    delay(10);
    digitalWrite(buzzer,  HIGH);
    digitalWrite(hieght, LOW);
    digitalWrite(width, HIGH);
    delay(250);
    digitalWrite(buzzer,LOW);
    str_distance = String(distance);
    status = str_distance + "/width";
    myserial.println(status);
    Serial.println(status);


    }
    
  
  
  }

