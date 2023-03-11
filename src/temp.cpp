#include "temperature.h"
#define RESIST 102000 
#define B_NTC 3950 
#define THERMISTOR_RESIST_NOMINAL 100000 
#define NOMINAL_TEMP 25 
#define tempPin A0
void temperature::gradus(){ 
  
  int ANALOG_TEMP = analogRead(tempPin); 
  float THERMISTOR_RESIST = 1023.0/ ANALOG_TEMP-1; 
  THERMISTOR_RESIST = RESIST / THERMISTOR_RESIST; 
 
  float GetCelsius ;
  GetCelsius = THERMISTOR_RESIST / THERMISTOR_RESIST_NOMINAL; 
  GetCelsius = log(GetCelsius);  
  GetCelsius /= B_NTC; 
  GetCelsius += 1.0 / (NOMINAL_TEMP + 273.15); 
  GetCelsius = 1.0 / GetCelsius; 
  GetCelsius -= 273.15; 
  temp = GetCelsius;
  return temp
}
