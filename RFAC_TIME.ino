/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Control de Tiempo             *
********************************/

//Imprime la Hora en la TFT y el LCD
void getHour() {
  writeTFTLn(40,225,WHITE,2,getNow());
  printLCD(0,3,getNow());
}

//Obtiene la Fecha
String getDay() {
  String hr = "";
  String months[] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun",
                     "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
  if (day()<10) { hr += "0"; }
  hr.concat(day());
  hr += "-";
  hr.concat(months[month()-1]);
  hr += "-";
  hr.concat(year());
  return hr;
}

//Obtiene el Mes para los Ficheros de Estadísticas
String getMonthStat() {
  String hr = "";
  String months[] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun",
                     "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
  hr.concat(year());
  hr.concat(months[month()-1]);
  return hr;
}

//Obtiene la Hora
String getTime() {
  String hr = "";
  if (hour()<10) { hr += "0"; }
  hr.concat(hour());
  hr += ":";
  if (minute()<10) { hr += "0";}
  hr.concat(minute());
  hr += ":";
  if (second()<10) { hr += "0"; }
  hr.concat(second());
  return hr;
}

//Obtiene la Hora sin Segundos
String getTimeLite() {
  String hr = "";
  if (hour()<10) { hr += "0"; }
  hr.concat(hour());
  hr += ":";
  if (minute()<10) { hr += "0";}
  hr.concat(minute());
  return hr;
}

//Obtiene la Fecha y Hora
String getNow() {
  String hr = getDay();
  hr += " ";
  hr.concat(getTime());
  return hr;
}

//Actualiza la Fecha y Hora del Reloj
void setHour(int hr, int mn, int sg, int dd, int mm, int yyyy) {
  setTime(hr, mn, sg, dd, mm, yyyy);
  RTC.set(now());
}

//Activa o Desactiva el Horario de Verano 
void setSummer(bool on) {
  int addHr = 1;
  if (!on) addHr = addHr*-1;
  setTime(hour()+addHr, minute(), second(), day(), month(), year());
  RTC.set(now());  
}
