/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Relays             *
********************************/

void initRelays() {
  for (int i=0; i<8; i++) {
    pinMode(rel_conec[i], OUTPUT);
    digitalWrite(rel_conec[i], HIGH);  
  }
  
  switch_cal=getParameter("Switch_Calentador").toInt();
  switch_sub=1;
  switch_ski=2;
  switch_cir=3;
  switch_bch=4;
  switch_chi=5;
  switch_bca=6;
  switch_sca=7;
}

void switch_relay(int origen) {
  if (rel_state[origen] == LOW) {
    rel_state[origen] = HIGH;
  } else {
    rel_state[origen] = LOW;
  }
  digitalWrite(rel_conec[origen], rel_state[origen]);  
}

void on_switch(int origen) {
  rel_state[origen] = HIGH;
  digitalWrite(rel_conec[origen], rel_state[origen]);  
}

void off_switch(int origen) {
  rel_state[origen] = LOW;
  digitalWrite(rel_conec[origen], rel_state[origen]);  
}

