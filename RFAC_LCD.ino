/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Controlador de LCD            *
********************************/

//Inicio Parámetros de Pantalla LCD
void initLCD() {
  lcd.init();
  pinMode(lcdBackPin, OUTPUT);
  pinMode(lcdLigthPin, OUTPUT);
  onScreen();
}

//Encencido de Pantalla LCD
void onScreen() {
  //Cada vez que enciendo la pantalla limpio 
  //los valores por que los caracteres se batian
  printLCD(0,0,"Reef-Life AC V 3.0  ");
  printLCD(0,1,"                    ");
  printLCD(0,2,"                    ");
  printLCD(0,3,"                    ");
  //Inicio la Luz de Respaldo de la Pantalla
  digitalWrite(lcdBackPin, HIGH);
  //Calibro a media luz las letras del LCD 
  analogWrite(lcdLigthPin, charLigth);
  
  //Imprimo la Informacion Básica del LCD
  showLED_LCD;    //Posicion de los LEDs
}

//Apagado de Pantalla LCD
void offScreen() {
  //Inicio la Luz de Respaldo de la Pantalla
  digitalWrite(lcdBackPin, LOW);
  //Calibro a media luz las letras del LCD 
  analogWrite(lcdLigthPin, charLigth);
}

//Imprimo un texto en el LCD
void printLCD(int col, int row, String data) {
  lcd.setCursor(col, row);
  lcd.print(data);
}

