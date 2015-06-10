/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control de Leds               *
********************************/

//Inicio los parámetros para el encendido de los LEDS
void initLeds() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  analogWrite(ledA, 0);
  analogWrite(ledB, 0);
  analogWrite(ledC, 0);
  analogWrite(ledD, 0);

  //Recupero los horarios de encendido y apagado de los LEDS  
  LedA_ON=getParameter("LedA_ON");
  LedB_ON=getParameter("LedB_ON");
  LedC_ON=getParameter("LedC_ON");
  LedD_ON=getParameter("LedD_ON");
  LedA_OFF=getParameter("LedA_OFF");
  LedB_OFF=getParameter("LedB_OFF");
  LedC_OFF=getParameter("LedC_OFF");
  LedD_OFF=getParameter("LedD_OFF");
  
  //Recupero la opcion de encendio automatico por cantidad de Luz;
  String autoLed = "";
  autoLed = getParameter("ledsAuto");
  if (autoLed.equals("false")){
    ledAuto=false;
  } else {
    ledAuto=true;
  }
  ledsInterval=getParameter("ledsInterval").toInt();
} 

//Modifico la salida del Pin de Led
void modPowerLED(int led, byte pot) {
  analogWrite(ledD, pot);
}

//Incremento la potencia por Canal
void addPowerLED(int led, int added) {
  byte ledSteps[29] = {  0, 12, 21, 30, 39, 48, 57, 66, 75, 84,
                        93,102,111,120,129,138,147,156,165,174,
                       183,192,201,210,219,228,237,246,255};  
  switch (led) {
    case 0:   //Canal Led A
      potA+=added;
      if (potA<0)  {potA=0; ledA_Off=false;}
      if (potA>28) {potA=28; ledA_On=false;}
      modPowerLED(ledA, ledSteps[added]);
      break;
    case 1:   //Canal Led B
      potB+=added;
      if (potB<0)  {potB=0; ledB_Off=false;}
      if (potB>28) {potB=28; ledB_On=false;}
      modPowerLED(ledB, ledSteps[added]);
      break;
    case 2:   //Canal Led C
      potC+=added;
      if (potC<0)  {potC=0; ledC_Off=false;}
      if (potC>28) {potC=28; ledC_On=false;}
      modPowerLED(ledC, ledSteps[added]);
      break;
    case 3:   //Canal Led D
      potD+=added;
      if (potD<0)  {potD=0; ledD_Off=false;}
      if (potD>28) {potD=28; ledD_On=false;}
      modPowerLED(ledD, ledSteps[added]);
      break;
    default:
      break;
  }
}

//Muestra el posicionamiento de los Canales de LED
void showLED_LCD() {
  byte ledSteps[29] = {  0, 12, 21, 30, 39, 48, 57, 66, 75, 84,
                        93,102,111,120,129,138,147,156,165,174,
                       183,192,201,210,219,228,237,246,255};  
  int posA = map(ledSteps[potA], 0, 100, 0, 255);  
  int posB = map(ledSteps[potB], 0, 100, 0, 255);  
  int posC = map(ledSteps[potC], 0, 100, 0, 255);  
  int posD = map(ledSteps[potD], 0, 100, 0, 255);  
  
  String info = "A:";
  if (posA<10) info+="  ";
  if (posA<100) info+=" ";
  info.concat(posA);
  info+="B:";
  if (posB<10) info+="  ";
  if (posB<100) info+=" ";
  info.concat(posB);
  info+="C:";
  if (posC<10) info+="  ";
  if (posC<100) info+=" ";
  info.concat(posC);
  info+="D:";
  if (posD<10) info+="  ";
  if (posD<100) info+=" ";
  info.concat(posD);
  printLCD(0,1,info);  
}
