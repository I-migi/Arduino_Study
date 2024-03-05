#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2
int t=0;
int h=0;
int r=3;
void setup(){
  Serial.begin(9600);
  pinMode(r,OUTPUT);
}
void dht11(){
    DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
}
void loop(){
  dht11();
  if(DHT.humidity < 50) {
    Serial.println("Turning on the humidifier...");
    digitalWrite(r, HIGH);
  }
  else {
    Serial.println("Turning off the humidifier...");
    digitalWrite(r, LOW);
  }
  delay(2000);
}
