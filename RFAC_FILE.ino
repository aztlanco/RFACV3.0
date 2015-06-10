/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Lectura y Escritura           *
* Archivos de Parámetros        *
* y Configuración               *
********************************/

//Abre el archivo de configración y busca un parámetro
String getParameter(String param) {
  String retVal    = "";
  String parGetted = "";
  String valGetted = "";
  int    valPar    = 0;
  SdFile parFile;
  if (parFile.open("config.ini")) {
    while (parFile.available()) {
      char value = parFile.read();
      if (value==13) {
        if (parGetted==param) { retVal = valGetted; break; }
        parGetted = "";
        valGetted = "";
        valPar    = 0;
      } else {
        if (value!=10) {
          if (value=='=') { valPar=1; }
          else {
            if (valPar==0) { parGetted.concat(value); } else { valGetted.concat(value); }
          }
        }
      }  
    }
    parFile.close();
  }
  return retVal;
}

//Actualiza el valor de un Parámetro en el Archivo de Configuración
void writeParameter(String param, String valueSetted) {
  String parGetted = "";
  String valGetted = "";
  String fileStr   = "";
  int    valPar    = 0;
  SdFile parFile;
  
  if (parFile.open("config.ini")) {
    while (parFile.available()) {
      char value = parFile.read();
      if (value==13) {
        fileStr.concat(parGetted);
        fileStr.concat("=");
        if (parGetted==param) { 
          fileStr.concat(valueSetted);
        } else {
          fileStr.concat(valGetted);
        }
        fileStr.concat(value);
        parGetted = "";
        valGetted = "";
        valPar    = 0;
      } else {
        if (value!=10) {
          if (value=='=') { valPar=1; }
          else {
            if (valPar==0) { parGetted.concat(value); } else { valGetted.concat(value); }
          }
        } else { fileStr.concat(value); }
      }  
    }
    parFile.close();
  }
  
  if (parFile.open("config.ini", O_WRITE | O_TRUNC)) {
    parFile.print(fileStr);
    parFile.close();
  }
}

//Guarda las estadísticas de las lecturas.
void writeStat(int type, String valueSetted) {
  String fileStr  = "";
  String fileName = "stats/";
  String newVal   = getNow();
  char   fName[255];
  SdFile statFile;

  switch (type) {
    case 1:
      fileName.concat("tmp");
    case 2:
      fileName.concat("ph1");
    case 3:
      fileName.concat("ph2");
    case 4:
      fileName.concat("ca_");
    case 5:
      fileName.concat("mg_");
    case 6:
      fileName.concat("no3");
    case 7:
      fileName.concat("no4");
    default:
      fileName.concat("log.txt");
      break;
  }
  fileName.concat(getMonthStat());
  fileName.concat(".txt");
  newVal += " ";
  newVal.concat(valueSetted);
  fileName.toCharArray(fName, 255);
  if (statFile.open(fName, O_RDWR | O_CREAT | O_AT_END)) {
    statFile.println(newVal);
    statFile.close();
  }
}
