/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Loop                          *
********************************/

void loop() {
  // Inicializo temporizadores
  static unsigned long clockTimmer = millis();
  static unsigned long feedTimmer  = millis();
  static unsigned long termTimmer  = millis();
  static unsigned long screenTimer = millis();  
  static unsigned long sensorTimer = millis();  
  
  static unsigned long ledTimmer = millis();  

  //Obtengo la Hora cada segundo
  if (millis()-clockTimmer >= 1000) {
    getHour();  
    clockTimmer=millis();
  }

  //Rutina de Alimentador
  if (startFeed) {
    feedTimmer = millis();
    startFeed = false;
  }
  if ((millis()-feedTimmer >= 2000) && (feed)) {
    validateFeed();
  }
  if ((getTime()==feedTime_1)||(getTime()==feedTime_2)) {
    feeding();
  }

  //Verifico la temperatura
  if (millis()-termTimmer > termInterval) {
    printTemperature_LCD();
    termTimmer=millis();
  }

  //Apago la pantalla LCD
  if (millis()-screenTimer > screenInterval) {
    offScreen();
  }  

  // Proceso de lectura del PH
  if (millis()-sensorTimer > sensorInterval) {
    getSensorValue(pH1_Pin, Offset_PH1);
    getSensorValue(pH2_Pin, Offset_PH2);
    getSensorValue(CA_Pin, Offset_CA);
    getSensorValue(MG_Pin, Offset_MG);
    getSensorValue(NO3_Pin, Offset_NO3);
    getSensorValue(NOA_Pin, Offset_NO4);
    sensorTimer = millis();
  }
  
  if (ledAuto) {
    //Encendido de Lamparas cuando esta el Modo Automatico
  } else {
    //Encendido de Lamparas cuando esta apagado el Modo Automatico
    if (millis()-ledTimmer > ledsInterval) {
      if (ledA_On) addPowerLED(0, 1);
      if (ledB_On) addPowerLED(1, 1);
      if (ledC_On) addPowerLED(2, 1);
      if (ledD_On) addPowerLED(3, 1);
      if (ledA_Off) addPowerLED(0, -1);
      if (ledB_Off) addPowerLED(1, -1);
      if (ledC_Off) addPowerLED(2, -1);
      if (ledD_Off) addPowerLED(3, -1);
      ledTimmer = millis();
    }
  }
  
  //Lectura de Accesos del Usuario
  validTouch();
  readKB();
  readIR();
  
  //Imprimo el valor del Photo Resitor (Momentaneamente)
  //lcd.setCursor(10, 1);
  //lcd.print("Luz: ");
  //lcd.print(analogRead(0)/2);
}

