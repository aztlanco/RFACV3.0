/****************************************************************
* Reef-Life Aquarium Controller                                 *
* Versión 3.0.0 - 201505                                        *
* Control del Alimentador                                       *
****************************************************************/

void initFeeder() {
  pinMode(feederPos, INPUT);  // Informa de la posicion del Alimentador 
  pinMode(feeder, OUTPUT);         // Ejecutara la accion
  feedTime_1 = getParameter("FeederTime1");
  feedTime_2 = getParameter("FeederTime2");
}

void feeding() {
  digitalWrite(feeder,HIGH);
  feed=true;
  startFeed=true;
}

void validateFeed() {
  if (digitalRead(feederPos)==LOW) {
    digitalWrite(feeder,LOW);
    feed=false;
  }		
}  

