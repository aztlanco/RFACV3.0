/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Tiempo             *
********************************/
void getHour() {
  //Serial.println(hr);
  writeTFTLn(40,225,WHITE,2,getNow());
}

String getDay() {
  String hr = "";
  String months[] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
  if (day()<10) { hr += "0"; }
  hr.concat(day());
  hr += "-";
  hr.concat(months[month()-1]);
  hr += "-";
  hr.concat(year());
  return hr;
}

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

String getTimeLite() {
  String hr = "";
  if (hour()<10) { hr += "0"; }
  hr.concat(hour());
  hr += ":";
  if (minute()<10) { hr += "0";}
  hr.concat(minute());
  return hr;
}

String getNow() {
  String hr = getDay();
  hr += " ";
  hr.concat(getTime());
  return hr;
}

void setHour(int hr, int mn, int sg, int dd, int mm, int yyyy) {
  setTime(hr, mn, sg, dd, mm, yyyy);
  RTC.set(now());
}

void setSummer(bool on) {
  int addHr = 1;
  if (!on) addHr = addHr*-1;
  setTime(hour()+addHr, minute(), second(), day(), month(), year());
  RTC.set(now());  
}
