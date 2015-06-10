/********************************
* Reef-Life Aquarium Controller *
* Versión 3.0.0 - 201506        *
* Declaraciones                 *
********************************/

/********************************
* Includes - Libraries          *
********************************/
#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <DallasTemperature.h>
#include <DS3232RTC.h>             
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <Keypad.h> 
#include <Keypad_I2C.h> 
#include <OneWire.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SPI.h>
#include <Time.h>                  
#include <TouchScreen.h>
#include <Wire.h>

/********************************
* Variables del LCD TFT         *
********************************/
#define LCD_RD A0 
#define LCD_WR A1 
#define LCD_CD A2 
#define LCD_CS A3 
#define LCD_RESET A4 
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0xD6D6
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

/********************************
* Variables del SDHC            *
********************************/
const uint8_t SOFT_MISO_PIN = 32;
const uint8_t SOFT_MOSI_PIN = 31;
const uint8_t SOFT_SCK_PIN  = 33;
const uint8_t SD_CHIP_SELECT_PIN = 30;
SdFatSoftSpi<SOFT_MISO_PIN, SOFT_MOSI_PIN, SOFT_SCK_PIN> sd;

/********************************
* Variables de Imagenes         *
********************************/
#define BUF_SIZE 10240
#define BUFFPIXEL 48
uint8_t buf[BUF_SIZE];
#define error(s) sd.errorHalt_P(PSTR(s))

/********************************
* Variables para TouchScreen    *
********************************/
#define YP A1  
#define XM A2  
#define YM 29
#define XP 28
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
#define MINPRESSURE 200
#define MAXPRESSURE 300

/********************************
* Variables para el Menu        *
********************************/
int SceneDisplay = 0;
boolean minus = false;

/********************************
* Definición de Contactos       *
********************************/
int rel_conec[8]={50, 48, 46, 44, 42, 40, 38, 36};
int rel_state[8]={HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
boolean bol_light = false;
int switch_cal=0;
int switch_sub=1;
int switch_ski=2;
int switch_cir=3;
int switch_bch=4;
int switch_chi=5;
int switch_bca=6;
int switch_sca=7;

/********************************
* Definición Teclado            *
********************************/
#define KYB_ADDR 0x21
#define ROWS 4 
#define COLS 4 
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {4,5,6,7}; 
byte colPins[COLS] = {0,1,2,3}; 
Keypad_I2C customKeypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS, KYB_ADDR); 

/********************************
* Definición Termómetros        *
********************************/
#define ONE_WIRE_BUS 53
long termInterval=0;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress thermA = { 0x28, 0xFF, 0x60, 0xF5, 0x15, 0x14, 0x00, 0x01 };
DeviceAddress thermB = { 0x28, 0xFF, 0x8A, 0x5A, 0x15, 0x14, 0x00, 0x55 };

/********************************
* Definición LCD                *
********************************/
#define lcdBackPin 13
#define lcdLigthPin 12
#define LCD_ADDR 0x20
#define charLigth 125
int screenInterval = 30000;
LiquidCrystal_I2C lcd(LCD_ADDR,20,4);

/********************************
* Definición de IR              *
********************************/
#define RECV_PIN 52
IRrecv irrecv(RECV_PIN);
decode_results results;

/********************************
* Definición de PH              *
********************************/
//Pines de los Sensores.
#define pH1_Pin A8
#define pH2_Pin A9
#define CA_Pin  A10
#define MG_Pin  A11
#define NO3_Pin A12
#define NOA_Pin A13
#define ArrayLength 50       

long sensorInterval=0;
long Offset_PH1 = 0;
long Offset_PH2 = 0;
long Offset_CA  = 0;
long Offset_MG  = 0;
long Offset_NO3 = 0;
long Offset_NO4 = 0;

/********************************
* Definición de Sensor de Luz   *
********************************/
#define ligthSensor A5

/********************************
* Definición de Leds            *
********************************/
#define photoPin 0
#define ledA 2
#define ledB 3
#define ledC 4
#define ledD 5
String LedA_ON = "";
String LedB_ON = "";
String LedC_ON = "";
String LedD_ON = "";
String LedA_OFF = "";
String LedB_OFF = "";
String LedC_OFF = "";
String LedD_OFF = "";
byte potA=0;
byte potB=0;
byte potC=0;
byte potD=0;
boolean ledAuto=false;
long ledsInterval=0;
boolean ledA_On=false;
boolean ledB_On=false;
boolean ledC_On=false;
boolean ledD_On=false;
boolean ledA_Off=false;
boolean ledB_Off=false;
boolean ledC_Off=false;
boolean ledD_Off=false;

/********************************
* Definición de Peristalticas   *
********************************/
#define periA 6
#define periB 7
#define periC 8
#define periD 9
#define periE 10
#define periF 11
String Peri_1_ON="";
String Peri_2_ON="";
String Peri_3_ON="";
String Peri_4_ON="";
String Peri_5_ON="";
String Peri_6_ON="";
String Peri_1_OFF="";
String Peri_2_OFF="";
String Peri_3_OFF="";
String Peri_4_OFF="";
String Peri_5_OFF="";
String Peri_6_OFF="";

/********************************
* Definición de Alimentador     *
********************************/
#define feeder    51
#define feederPos 49
boolean feed = false;
boolean startFeed = false;
String feedTime_1 = "";
String feedTime_2 = "";

