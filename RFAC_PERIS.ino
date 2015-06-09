/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201505        *
* Control de Peristalticas      *
********************************/

void initPeris() {
  pinMode(periA, OUTPUT);
  pinMode(periB, OUTPUT);
  pinMode(periC, OUTPUT);
  pinMode(periD, OUTPUT);
  pinMode(periE, OUTPUT);
  pinMode(periF, OUTPUT);

  Peri_1_ON=getParameter("Peri_1_ON");
  Peri_2_ON=getParameter("Peri_2_ON");
  Peri_3_ON=getParameter("Peri_3_ON");
  Peri_4_ON=getParameter("Peri_4_ON");
  Peri_5_ON=getParameter("Peri_5_ON");
  Peri_6_ON=getParameter("Peri_6_ON");
  Peri_1_OFF=getParameter("Peri_1_OFF");
  Peri_2_OFF=getParameter("Peri_2_OFF");
  Peri_3_OFF=getParameter("Peri_3_OFF");
  Peri_4_OFF=getParameter("Peri_4_OFF");
  Peri_5_OFF=getParameter("Peri_5_OFF");
  Peri_6_OFF=getParameter("Peri_6_OFF");
}
