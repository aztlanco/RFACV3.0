/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Sensores           *
********************************/

//Apertura de Puertos de Lectura e Inicio de Parametros
void initSensors() {
  pinMode(pH1_Pin, INPUT);
  pinMode(pH2_Pin, INPUT);
  pinMode(cA_Pin , INPUT);
  pinMode(mg_Pin , INPUT);
  pinMode(NO3_Pin, INPUT);
  pinMode(NOA_Pin, INPUT);

  sensorInterval=getParameter("sensorInterval").toInt();
  Offset_PH1=getParameter("Offset_PH1").toInt();
  Offset_PH2=getParameter("Offset_PH2").toInt();
  Offset_CA=getParameter("Offset_CA").toInt();
  Offset_MG=getParameter("Offset_MG").toInt();
  Offset_NO4=getParameter("Offset_NO4").toInt();
  Offset_NO3=getParameter("Offset_NO3").toInt();
}


// Recupera la salida del Sensor (PH, CA, MG, NO3, NO4)
// Por un muestro de 50 Tomas
String getSensorValue(int sensorPin, long offset) {
  String retVal="";

  float sensor=0;
  float sensorValue=0;
  float sensorArray[ArrayLength];    

  for(int i=0; i<ArrayLength; i++) {
    sensorArray[i]=analogRead(sensorPin);
  }
  sensor = promedio(sensorArray,ArrayLength)*5.0/1024;
  sensorValue=3.5*sensor+offset;
  retVal+=String(int(sensorValue))+ "."+String(getDecimal(sensorValue)); 
}

// Calcula el Promedio del Muestreo
float promedio(float* array, int length) {
  float aux=0;
  for (int i=0; i<length; i++) {
    aux += array[i];
  }
  return aux/length;
}


