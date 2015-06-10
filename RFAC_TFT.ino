/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control de TFT                *
********************************/

//Inicializo los Parámetros del TFT
void initTFT() {
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(3);
  tft.fillScreen(BLACK);
  writeTFTLn(0,0,YELLOW,1.5,"Reef-Life Aquarium Controller V3.0");
  getHour();
  
  //Area de ventana y Menu de Opciones
  bmpDraw("imgs/clock.bmp", 2,  10);
  bmpDraw("imgs/onoff.bmp", 2,  58);
  bmpDraw("imgs/timer.bmp", 2, 106);
  bmpDraw("imgs/stats.bmp", 2, 154);
  switchMenu(0);
}

//Pone un Texto en el TFT
void writeTFTLn(int x, int y, uint16_t color, int font, String text) {
  tft.setTextSize(font);
  tft.setCursor(x, y);
  tft.setTextColor(color, BLACK);  
  tft.println(text);
}

//Realiza los cambios del Menu
void switchMenu(int newMenu) {
  uint16_t color;
  if (newMenu==3) {color=GREEN;} else {color=BLUE;}
  tft.drawRect(2, 10, 48, 48, color);
  if (newMenu==2) {color=GREEN;} else {color=BLUE;}
  tft.drawRect(2, 58, 48, 48, color);
  if (newMenu==1) {color=GREEN;} else {color=BLUE;}
  tft.drawRect(2, 106, 48, 48, color);
  if (newMenu==0) {color=GREEN;} else {color=BLUE;}
  tft.drawRect(2, 154, 48, 48, color);  
  SceneDisplay = newMenu;
  getScreen(newMenu);
}

//Pone la pantalla de acuerdo a la seleccion del Menu
void getScreen(int menu) {
  uint16_t color;
  
  if (menu==3) {
    String summer = getParameter("Summer");
    writeTFTLn( 84,  35, WHITE, 3, getDay());
    writeTFTLn(118,  80, WHITE, 3, getTime());
    writeTFTLn(115, 125, WHITE, 3, "Verano");
    if (summer=="ON") { bmpDraw("imgs/green.bmp", 233, 125); } else { bmpDraw("imgs/red.bmp", 233, 125); }
    if (minus) {color=BLUE;} else {color=GREEN;}  
    bmpDraw("imgs/more.bmp" , 114, 170);
    tft.drawRect(114, 170, 48, 48, color);  
    if (minus) {color=GREEN;} else {color=BLUE;}  
    bmpDraw("imgs/minus.bmp", 210, 170);
    tft.drawRect(210, 170, 48, 48, color);  
  }
}
