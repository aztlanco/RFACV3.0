/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Teclado            *
********************************/

void initKeyBoard() {
  customKeypad.begin();
}

void readKB() {
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
      //ledElapsed = demoInterval;
      //doAmanecer=true;
      amanecer();
      //ledTimmer=millis();
    }      // Press * Demo de amanecer
    if (customKey == '#') { 
      //ledElapsed = demoInterval;
      //doAnochece=true;
      anochecer();
      //ledTimmer=millis();
    }     // Press # Demo de anochecer
    if (customKey == 'C') {       
      //ledElapsed = demoInterval/4;
      //doAmanecer_blue=true;
      amanecer_blue();
      //ledTimmer=millis();
    }      // Press * Demo de amanecer
    if (customKey == 'D') { 
      //ledElapsed = demoInterval/4;
      //doAnochece_blue=true;
      anochecer_blue();
      //ledTimmer=millis();
    }     // Press # Demo de anochecer
    //screenTimer = millis();
  }
}
