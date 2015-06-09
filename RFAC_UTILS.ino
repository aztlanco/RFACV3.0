/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Funciones Generales           *
********************************/

// Obtiene los decimales de un Float
// en un Long para poder convertirlo a String
long getDecimal(float val) {
  int intPart = int(val);
  long decPart = 1000*(val-intPart); 
  if(decPart>0)return(decPart);
  else if(decPart<0)return((-1)*decPart);
  else if(decPart=0)return(00);
}
