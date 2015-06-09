/********************************
* Reef-Life Aquarium Controller *
* Versión 1.0.1 - 201503        *
* Controlador de LCD            *
********************************/

void initLCD() {
  lcd.init();
  pinMode(lcdBackPin, OUTPUT);
  pinMode(lcdLigthPin, OUTPUT);
  onScreen();
}

void onScreen() {
  lcd.setCursor(0, 0);
  lcd.print("Reef-Life Aquarium  ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  get_PH();
  lcd.setCursor(0, 2);
  lcd.print("                    ");
  printTemperature();
  lcd.setCursor(0, 3);
  lcd.print("                    ");
  getHour();

  //Inicio la Luz de Respaldo de la Pantalla
  digitalWrite(lcdBackPin, HIGH);
  //Calibro a media luz las letras del LCD 
  analogWrite(lcdLigthPin, charLigth);
}

void offScreen() {
  //Inicio la Luz de Respaldo de la Pantalla
  digitalWrite(lcdBackPin, LOW);
  //Calibro a media luz las letras del LCD 
  analogWrite(lcdLigthPin, charLigth);
}

