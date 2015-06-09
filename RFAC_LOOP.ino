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
  //static unsigned long screenTimer = millis();  
  //static unsigned long pHreadTimer = millis();  
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

  /*
  //Apago la pantalla para guardar LCD
  if (millis()-screenTimer > screenInterval) {
    offScreen();
  }  

  // Proceso de lectura del PH
  if (millis()-pHreadTimer > pHreadInterval) {
    get_PH();
    pHreadTimer = millis();
  }
  
  char customKey = customKeypad.getKey(); 
  if (customKey != NO_KEY){
    onScreen();
    //if (customKey == '1') { switch_relay(0); }
    if (customKey == '2') { switch_relay(1); }
    if (customKey == '3') { switch_relay(2); }
    if (customKey == '4') { switch_relay(3); }
    if (customKey == '5') { switch_relay(4); }
    if (customKey == '6') { switch_relay(5); }
    if (customKey == '*') {       
      ledElapsed = demoInterval;
      doAmanecer=true;
      amanecer();
      ledTimmer=millis();
    }      // Press * Demo de amanecer
    if (customKey == '#') { 
      ledElapsed = demoInterval;
      doAnochece=true;
      anochecer();
      ledTimmer=millis();
    }     // Press # Demo de anochecer
    if (customKey == 'C') {       
      ledElapsed = demoInterval/4;
      doAmanecer_blue=true;
      amanecer_blue();
      ledTimmer=millis();
    }      // Press * Demo de amanecer
    if (customKey == 'D') { 
      ledElapsed = demoInterval/4;
      doAnochece_blue=true;
      anochecer_blue();
      ledTimmer=millis();
    }     // Press # Demo de anochecer
    screenTimer = millis();
  }
  
  // Leo el IR   
  /*
  Faltan por configurar del IR   
  IR_7 8C22657B
  IR_8 488F3CBB
  IR_9 449E79F
  IR_0 1BC0157B
  IR_OK D7E84B1B
  IR_RI 20FE4DBB
  IR_LE 52A3D41F
  IR_UP 511DBB
  IR_DO A3C8EDDB
  */
  /*
  if (irrecv.decode(&results)) {
    //if (results.value == 0xC101E57B) { switch_relay(0); } // Press 1
    if (results.value == 0x97483BFB) { switch_relay(1); } // Press 2
    if (results.value == 0xF0C41643) { switch_relay(2); } // Press 3
    if (results.value == 0x9716BE3F) { switch_relay(3); } // Press 4
    if (results.value == 0x3D9AE3F7) { switch_relay(4); } // Press 5
    if (results.value == 0x6182021B) { switch_relay(5); } // Press 6
    if (results.value == 0x32C6FDF7) { 
      ledElapsed = demoInterval;
      doAmanecer=true;
      amanecer();
      ledTimmer=millis();
    }      // Press * Demo de amanecer
    if (results.value == 0x3EC3FC1B) { 
      ledElapsed = demoInterval;
      doAnochece=true;
      anochecer();
      ledTimmer=millis();
    }     // Press # Demo de anochecer
    irrecv.resume(); // Receive the next value
  }

  //Controlo el Amanecer
//  if ((hourNow==timeAmanecer) && (doAmanecer==false)) {
//    ledElapsed=ledInterval;
//    doAmanecer=true;
//    amanecer();
//    ledTimmer=millis();
//  }

  if ((millis()-ledTimmer>ledElapsed) && (doAmanecer==true)) {
    amanecer();
    ledTimmer=millis();
  }

  if ((millis()-ledTimmer>ledElapsed) && (doAmanecer_blue==true)) {
    amanecer_blue();
    ledTimmer=millis();
  }
  
  //Controlo el Anochecer
//  if ((hourNow==timeAnochece) && (doAnochece==false)) {
//    ledElapsed = ledInterval;
//    doAnochece=true;
//    anochecer();
//    ledTimmer=millis();
//  }
  if ((millis()-ledTimmer>ledElapsed) && (doAnochece==true)) {
    anochecer();
    ledTimmer=millis();
  }
  if ((millis()-ledTimmer>ledElapsed) && (doAnochece_blue==true)) {
    anochecer_blue();
    ledTimmer=millis();
  }
  
  //Imprimo el valor del Photo Resitor (Momentaneamente)
  //lcd.setCursor(10, 1);
  //lcd.print("Luz: ");
  //lcd.print(analogRead(0)/2);
  */
}

