/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control de Relays             *
********************************/

//Inicio los parámetros para los Relays
void initRelays() {
  for (int i=0; i<8; i++) {
    pinMode(rel_conec[i], OUTPUT);
    digitalWrite(rel_conec[i], HIGH);  
  }
  
  switch_cal=getParameter("Switch_Calentador").toInt();
  switch_sub=getParameter("Switch_Subida").toInt();
  switch_ski=getParameter("Switch_Skimmer").toInt();
  switch_cir=getParameter("Switch_Circulacion").toInt();
  switch_bch=getParameter("Switch_BombaChiller").toInt();
  switch_chi=getParameter("Switch_Chiller").toInt();
  switch_bca=getParameter("Switch_BombaCA").toInt();
  switch_sca=getParameter("Switch_SolenoideCA").toInt();
}

//Apagado de Puerto
void switch_relay(int origen) {
  if (rel_state[origen] == LOW) {
    rel_state[origen] = HIGH;
  } else {
    rel_state[origen] = LOW;
  }
  digitalWrite(rel_conec[origen], rel_state[origen]);  
}

//Encendido de Puerto
void on_switch(int origen) {
  rel_state[origen] = HIGH;
  digitalWrite(rel_conec[origen], rel_state[origen]);  
}

//Apagado de Puerto
void off_switch(int origen) {
  rel_state[origen] = LOW;
  digitalWrite(rel_conec[origen], rel_state[origen]);  
}

