/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control del Alimentador       *
********************************/

//Inicio parámetros del Alimentador
void initFeeder() {
  pinMode(feederPos, INPUT);                // Pin que Informa de la posicion del Alimentador 
  pinMode(feeder, OUTPUT);                  // Pin que enciende el Alimentador
  feedTime_1 = getParameter("FeederTime1"); // Primer hora de Alimentación
  feedTime_2 = getParameter("FeederTime2"); // Segunda hora de Alimentación
}

//Alimentación enciende el Alimentador
void feeding() {
  digitalWrite(feeder,HIGH);
  feed=true;
  startFeed=true;
}

//Verifica que este girando cuando 
//termina la vuelta apaga el Alimentador
void validateFeed() {
  if (digitalRead(feederPos)==LOW) {
    digitalWrite(feeder,LOW);
    feed=false;
  }		
}  

