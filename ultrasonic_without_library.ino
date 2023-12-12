#define trig 11
#define echo 12
int distance = 0,t=0;
void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(trig,INPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t=pulseIn(echo,HIGH);
  distance = t/57;
  Serial.println(distance);
  delay(500);
    


}
