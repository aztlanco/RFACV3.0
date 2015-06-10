/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Controlador de Temperatura    *
********************************/

//Inicializo los Parámetros de Temperatura
void initTemp() {
  sensors.begin();
  sensors.setResolution(thermA, 10);
  sensors.setResolution(thermB, 10);
  termInterval=getParameter("termInterval").toInt();
  printTemperature_LCD();
}

//Imprime temperatura en LCD
void printTemperature_LCD() {
  String temps="T1:";
  sensors.requestTemperatures();
  float tempA = sensors.getTempC(thermA);
  float tempB = sensors.getTempC(thermB);

  temps+=String(int(tempA))+ "."+String(getDecimal(tempA)); 
  temps+=" T2:";
  temps+=String(int(tempB))+ "."+String(getDecimal(tempB)); 
  printLCD(0,2,temps);  
  String date = getNow() + temps;
  writeStat(1, date);
  if (tempA<25) { 
    on_switch(switch_cal);
  } 
  if (tempA>25.25) {
    off_switch(switch_cal);
  }
}
