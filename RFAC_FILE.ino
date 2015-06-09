/****************************************************************
* Reef-Life Aquarium Controller                                 *
* Versión 3.0.0 - 201505                                        *
* Lectura y Escritura de Archivos de Parámetros y Configuración *
****************************************************************/

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

void writeStat(int type, String valueSetted) {
  String fileStr  = "";
  String fileName = "stats/";
  String newVal   = getNow();
  char   fName[255];
  SdFile statFile;

  switch (type) {
    case 1:
      fileName.concat("temperatura.txt");
    default:
      fileName.concat("log.txt");
      break;
  }
  newVal += " ";
  newVal.concat(valueSetted);
  fileName.toCharArray(fName, 255);
  if (statFile.open(fName, O_RDWR | O_CREAT | O_AT_END)) {
    statFile.println(newVal);
    statFile.close();
  }
}
