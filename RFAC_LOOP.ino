/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Loop                          *
********************************/

void loop() {
  // Inicializo temporizadores
  static unsigned long clockTimmer = millis();
  static unsigned long feedTimmer  = millis();
  static unsigned long termTimmer  = millis();
  static unsigned long screenTimer = millis();  
  static unsigned long sensorTimer = millis();  
  //static unsigned long ledTimmer = millis();  

  //Obtengo la Hora cada segundo
  if (millis()-clockTimmer >= 1000) {
    getHour();  
    clockTimmer=millis();
  }
  validTouch();

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
    printTemperature();
    termTimmer=millis();
  }

  //Apago la pantalla LCD
  if (millis()-screenTimer > screenInterval) {
    offScreen();
  }  

  // Proceso de lectura del PH
  if (millis()-sensorTimer > sensorInterval) {
    //get_PH();
    sensorTimer = millis();
  }
  
  //Lectura de Teclado e IR
  readKB();
  readIR();
  
  //Imprimo el valor del Photo Resitor (Momentaneamente)
  //lcd.setCursor(10, 1);
  //lcd.print("Luz: ");
  //lcd.print(analogRead(0)/2);
}

