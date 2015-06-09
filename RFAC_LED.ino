/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control de Leds               *
********************************/

void initLeds() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  analogWrite(ledA, 0);
  analogWrite(ledB, 0);
  analogWrite(ledC, 0);
  analogWrite(ledD, 0);
} 

void anochecer() {
  /*
  if (doPointerA<29) {
    pwmA = stepLigth[doPointerA];
    doPointerA ++;
    analogWrite(ledA, pwmA);
  } else {
    if (doPointerB<26) {
      pwmB = stepLigth[doPointerB];
      doPointerB ++;
      analogWrite(ledB, pwmB);
    } else {
      doAnochece=false;
      doPointerA=28;
      doPointerB=28;
      ledElapsed=ledInterval;
    }
  }
  lcd.setCursor(9, 1);
  lcd.print("B: ");
  lcd.print(doPointerB);  
  lcd.print("W: ");
  lcd.print(doPointerA);  
  */
}

void amanecer() {
  /*
  if (doPointerB>7) {
    pwmB = stepLigth[doPointerB];
    doPointerB--;
    analogWrite(ledB, pwmB);
  } else {
    if (doPointerA>0) {
      pwmA = stepLigth[doPointerA];
      doPointerA--;
      analogWrite(ledA, pwmA);
    } else {
      doAmanecer=false;
      doPointerA=7;
      doPointerB=0;
      ledElapsed=ledInterval;
    }
  }
  lcd.setCursor(9, 1);
  lcd.print("B:");
  lcd.print(doPointerB);  
  lcd.print(" W:");
  lcd.print(doPointerA);  
  */
}

void anochecer_blue() {
  /*
  if (doPointerB<28) {
    pwmB = stepLigth[doPointerB];
    doPointerB ++;
    analogWrite(ledB, pwmB);
  } else {
    doAnochece_blue=false;
    doPointerA=26;
    doPointerB=28;
    ledElapsed=ledInterval;
  }
  lcd.setCursor(9, 1);
  lcd.print("B: ");
  lcd.print(doPointerB);  
  lcd.print("W: ");
  lcd.print(doPointerA);  
  */
}

void amanecer_blue() {
  /*
  if (doPointerB>0) {
    pwmB = stepLigth[doPointerB];
    doPointerB--;
    analogWrite(ledB, pwmB);
  } else {
    doAmanecer_blue=false;
    doPointerA=7;
    doPointerB=0;
    ledElapsed=ledInterval;
  }
  lcd.setCursor(9, 1);
  lcd.print("B:");
  lcd.print(doPointerB);  
  lcd.print(" W:");
  lcd.print(doPointerA);  
  */
}

