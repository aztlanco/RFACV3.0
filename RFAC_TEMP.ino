/********************************
* Reef-Life Aquarium Controller *
* Versión 1.0.0 - 201503        *
* Controlador de Temperatura    *
********************************/

void initTemp() {
  sensors.begin();
  sensors.setResolution(thermA, 10);
  sensors.setResolution(thermB, 10);
  termInterval=getParameter("termInterval").toInt();
  printTemperature();
}

void printTemperature() {
  //Recupero Temperaturas.
  sensors.requestTemperatures();
  float tempA = sensors.getTempC(thermA);
  float tempB = sensors.getTempC(thermB);

  lcd.setCursor(0, 2);
  lcd.print("T1:");
  lcd.print(tempA);
  lcd.print(" T2:");
  lcd.print(tempB);

  if (tempA<25) { 
    on_switch(switch_cal);
  } 
  if (tempA>25.25) {
    off_switch(switch_cal);
  }
}
