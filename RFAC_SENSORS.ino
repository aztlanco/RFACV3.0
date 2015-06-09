/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Relays             *
********************************/

void get_PH() {
  float pH=0;
  float pHValue=0;
/*  static unsigned long samplingTime = millis();
  static float pHValue,voltage;
  
  while (pHArrayIndex<ArrayLenth) {
    if(millis()-samplingTime > samplingInterval) {
        pHArray[pHArrayIndex++]=analogRead(pHsensorPin);
        voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
        pHValue = 3.5*voltage+Offset;
        samplingTime=millis();
    }
  }
  if(pHArrayIndex==ArrayLenth) pHArrayIndex = 0;7*/
  for(int i=0; i<ArrayLength; i++) {
    pHArray[i]=analogRead(pH1_Pin);
  }
  pH = promedio(pHArray,ArrayLength)*5.0/1024;
  pHValue=3.5*pH+Offset;
  lcd.setCursor(0, 1);
  lcd.print("pH: ");
  lcd.print(pHValue,2);
}

float promedio(float* array, int length) {
  float aux=0;
  for (int i=0; i<length; i++) {
    aux += array[i];
  }
  return aux/length;
}

