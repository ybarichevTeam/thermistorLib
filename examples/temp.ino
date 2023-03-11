#include "temperature.h"
temperature temp1;

void setup(){
  Serial.begin(9600);
  temp1.gradus();
}
