/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control de Touch Screen       *
********************************/

//Valida la posicion presionada en Pantalla
//De acuerdo a la opcion vigente del Menu
void validTouch() {
  int xP, yP;
  digitalWrite(SOFT_SCK_PIN, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(SOFT_SCK_PIN, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    xP = 320 - map(p.x, 100, 930, 0, tft.width());
    yP = map(p.y, 150, 920, 0, tft.height());
    if ((xP>=2) && (xP<=50)) {
      //Area de Botones de pantalla inicial
      if ((yP>=10) && (yP<58)) {
        //Ajustes de Hora
        minus = false;
        switchMenu(3);
      }
      if ((yP>=58) && (yP<106)) {
        //Encendido y Apagado Manual de Contactos
        switchMenu(2);
      }
      if ((yP>=106) && (yP<154)) {
        //Fijado de Timers 
        switchMenu(1);
      }
      if ((yP>=154) && (yP<202)) {
        //Vista General
        switchMenu(0);
      }
    }
    //Valido opciones de Ajustes de Hora
    if (SceneDisplay==3) {


      //Ajuste de Horario de Verano
      if (((xP>=115)&&(xP<=257)) && ((yP>=125) && (yP<=149))) {
        String summer = getParameter("Summer");
        //Serial.println("Antes SUMMER="+summer);
        setSummer(!(summer=="ON"));
        if (summer=="ON") {summer="OFF";} else {summer="ON";}
        //Serial.println("Despues SUMMER="+summer);
        writeParameter("Summer", summer);
        getScreen(3);
      }
      
      //Ajuste de Añadir 
      if (((xP>=114)&&(xP<=162)) && ((yP>=170) && (yP<=218))) {
        minus = false;
        getScreen(3);
      }
      
      //Ajuste de Disminuir 
      if (((xP>=210)&&(xP<=258)) && ((yP>=170) && (yP<=218))) {
        minus = true;
        getScreen(3);
      }
    }
  }
}

