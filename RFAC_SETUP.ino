/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Setup                         *
********************************/

void setup() {
  //Monitor serial para depuracion de codigo
  //Serial.begin(9600);
  
  setSyncProvider(RTC.get);   
  if (!sd.begin(SD_CHIP_SELECT_PIN)) {
    sd.initErrorHalt();
  }
  initTFT();
  initFeeder();
  initLeds();
  initKeyBoard();
  initIR();
  initRelays();
  initLCD();
  initTemp();
}


