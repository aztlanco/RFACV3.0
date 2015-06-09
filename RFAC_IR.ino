/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control Remoto                *
********************************/

void initIR() {
  irrecv.enableIRIn();
}

void readIR() {

  // Leo el IR   
  /*
  Faltan por configurar del IR   
  IR_9 449E79F
  IR_0 1BC0157B
  IR_OK D7E84B1B
  IR_RI 20FE4DBB
  IR_LE 52A3D41F
  IR_UP 511DBB
  IR_DO A3C8EDDB
  */
  
  if (irrecv.decode(&results)) {
    if (results.value == 0xC101E57B) { switch_relay(0); } 
    if (results.value == 0x97483BFB) { switch_relay(1); } 
    if (results.value == 0xF0C41643) { switch_relay(2); } 
    if (results.value == 0x9716BE3F) { switch_relay(3); } 
    if (results.value == 0x3D9AE3F7) { switch_relay(4); } 
    if (results.value == 0x6182021B) { switch_relay(5); } 
    if (results.value == 0x8C22657B) { switch_relay(6); } 
    if (results.value == 0x488F3CBB) { switch_relay(7); } 
    
    // Press * Amanecer
    if (results.value == 0x32C6FDF7) { 
      //ledElapsed = demoInterval;
      //doAmanecer=true;
      amanecer();
      //ledTimmer=millis();
    }
    // Press # Demo de Anochecer
    if (results.value == 0x3EC3FC1B) { 
      //ledElapsed = demoInterval;
      //doAnochece=true;
      anochecer();
      //ledTimmer=millis();
    }
    irrecv.resume(); // Receive the next value
  }
}
