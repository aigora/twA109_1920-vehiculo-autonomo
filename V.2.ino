#include <LiquidCrystal.h>
#include <Servo.h>

// Constantes
#define VEL 460    // velocidad del motor 
#define IZQ 60
#define MIZQ 75
#define CEN 100
#define MDCHA 125
#define DCHA 140
#define TOL 60

// Variables motor
int ENA = 11; 
int IN1 = 13;
int IN2 = 12;

// Variables voltimetro 
float bateria = A0; // Pin analogico conectado a la batería 
float voltaje = 0.0; // variable para la bateria 
int valor = 0; // variable para la bateria 
float R1 = 100000.0; // valor de la resistencia 1 
float R2 = 10000.0; // valor de la resistencia 2 
 
// Variables LCD
LiquidCrystal lcd(8,2,4,5,6,7); // LCD pines
int V0=9;                       //Pin donde se conecta el LCD para regular su contraste

// Variables generales
int linea,fuera;
int SLI,SCI,SC,SCD,SLD;
Servo myservo;  // crea el objeto servo

// Funciones prototipo
void voltimetro(void);
void inicioPantalla(void);
void motor(void);


void setup()
{
  Serial.begin(9600);

  pinMode(bateria, INPUT);  // Declaramos el pin de bateria como entrada
  pinMode (ENA, OUTPUT);    // Pines de motor como salida
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);

  myservo.attach(10);  // vincula el servo al pin digital 10
      
  analogWrite(V0,100);      //Contraste LCD
  lcd.begin(16,2);          //Definimos que las dimensiones del LCD es de 16x2

  inicioPantalla();
  
}

void loop()
{

  voltimetro(); 
  motor();
  
  SLI = analogRead(A1);
  SCI = analogRead(A2);
  SC = analogRead(A3);
  SCD = analogRead(A4);
  SLD = analogRead(A5); 

  Serial.println(SC);

   if (SC >= linea-TOL && SC <= linea+TOL)
      myservo.write(CEN);
   else if(SCI >= linea-TOL && SCI <= linea+TOL) 
          myservo.write(MIZQ);
          else if(SCD >= linea-TOL && SCD <= linea+TOL)
                 myservo.write(MDCHA);
                 else if(SLI >= linea-TOL && SLI <= linea+TOL)
                        myservo.write(IZQ);
                        else if (SLD >= linea-TOL && SLD <= linea+TOL)
                              myservo.write(DCHA);
                              
}


void voltimetro(void)
{ 
  valor = analogRead(bateria);
  voltaje = (valor * 4.8) / 1024.0;   // El valor de 5.x se puede ajustar para mejorar la exactitud de la lectura
  voltaje = voltaje / (R2/(R1+R2));
 // Serial.println(voltaje);

  lcd.clear();
  lcd.print("Voltaje bateria:");
  lcd.setCursor(0,1);
  lcd.print(voltaje);
  delay(1000);
}

void inicioPantalla(void)
{
  int mediaL = 0; 
  int mediaF = 0;
  int i,j; 

  lcd.clear();
  lcd.setCursor(3,0); 
  lcd.print("Iniciando");
  for(i=0;i<16;i++)
  {
    lcd.setCursor(i,1);
    lcd.print("-");
    delay(250);
  }

  lcd.clear();
  lcd.print("Preparese, situe");
  lcd.setCursor(0,1);
  lcd.print("el coche:");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sobre la linea");
  delay(2000);
  for(i=0;i<16;i++)
  {
   Serial.print("Lectura: ");
   Serial.println(analogRead(A3));
   mediaL = mediaL + analogRead(A3); 
   Serial.println(mediaL);

   lcd.setCursor(i,1);
   lcd.print("+");
   delay(500);
  }
  
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fuera de ella");
  delay(2000);
  for(j=0;j<16;j++)
  {
   Serial.print("Lectura: ");
   Serial.println(analogRead(A3));
   mediaF = mediaF + analogRead(A3); 
   Serial.println(mediaF);

   lcd.setCursor(j,1);
   lcd.print("+");
   delay(500);
  }

  linea = mediaL/16;
  fuera = mediaF/16;

  Serial.print("FUERA: ");
  Serial.println(fuera);

  Serial.print("LINEA: ");
  Serial.println(linea);

  delay(2000);
}

void motor(void)
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, VEL); //Velocidad motor A
}



  
