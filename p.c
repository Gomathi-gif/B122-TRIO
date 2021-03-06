#include <OneWire.h> 
#include <DallasTemperature.h>          
#define ONE_WIRE_BUS 4                                                                
OneWire oneWire(ONE_WIRE_BUS);
float temp; 
DallasTemperature sensors(&oneWire);
int sensorPin = A0;
double alpha = 0.75;
int period = 2000;
double change = 0.0;
double minval = 0.0;
void setup ()
{
  Serial.begin (9600);
  pinMode(A0,INPUT);
 sensors.begin(); 
}
void loop ()
{
    static double oldValue = 0;
    static double oldChange = 0;
 
    int rawValue = analogRead (A0);
    double value = alpha * oldValue + (1 - alpha) * rawValue;
 
    oldValue = value;
     sensors.requestTemperatures();
  temp=sensors.getTempCByIndex(0);
  temp=(temp*1.8)+32;
 Serial.print(temp);
 Serial.print(",");
 Serial.println(value/11);
 
 
    delayMicroseconds(100);
}
