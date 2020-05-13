#include <LiquidCrystal.h>
#include <Servo.h>

#define CEN 100
#define MIN 130
#define MAX 70

  // Motor 
 int ENA = 11;
 int IN1 = 13;
 int IN2 = 12;


  //Servo 
Servo servo; // crea el objeto servo
int pos = 0; 

  // Variables LCD
LiquidCrystal lcd(8,2,4,5,6,7); // Pineas a los que esta conectado el lcd
int V0=9; //Pin donde se conecta el lcd para regular su contraste
int i=0;

  // Variables del voltimetro 
float bateria = A0; // Pin analogico conectado a la batería 
float voltaje = 0.0; // variable para la bateria 
int valor = 0; // variable para la bateria 
float R1 = 100000.0; // valor de la resistencia 1 
float R2 = 10000.0; // valor de la resistencia 2 
 

  //Voltaje bateria 
 void medvoltaje(void)
 {
 valor = analogRead(bateria);
 voltaje = (valor * 4.5) / 1024.0; // El valor de 5.x se puede ajustar para mejorar la exactitud de la lectura
 voltaje = voltaje / (R2/(R1+R2));
 lcd.setCursor(5,1);
 lcd.print(voltaje); 
 }

  // Función encargada de mostrar el mensaje de inicio en pantalla
void inicioPantalla ()
{
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
  for(i=0;i<16;i++)
  {
    lcd.setCursor(i,1);
    lcd.print("+");
    delay(500);
  }

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Fuera de ella");
  for(i=0;i<16;i++)
  {
    lcd.setCursor(i,1);
    lcd.print("+");
    delay(500);
  }

  lcd.clear();

  lcd.print("El programa se");
  lcd.setCursor(0,1);
  lcd.print("iniciara en 5s");
  delay(5000);

  lcd.setCursor(0,0);
  lcd.print("Voltaje  bateria");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
}


void setup() 
{
  Serial.begin(9600);
  servo.attach (10); // servo conectado al pin 10
  pinMode(bateria,INPUT); 
  analogWrite(V0,120); //Contraste LCD
  lcd.begin(16,2); //Definimos que las dimensiones de la pantalla es de 16x2
  inicioPantalla(); // Funición mensajes de inicio

    // Motor 

 pinMode (ENA, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
  

    // Función de prueba del servo
  
   servo.write(CEN);
   delay(2000);
   servo.write(MIN);
   delay(2000);
   servo.write(MAX);
   delay(2000);
   servo.write(CEN);
   delay(2000);

 }

 
void loop() 
{

  medvoltaje();
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 150);   // velocidad motor A 
  delay(3000);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 150); 
  delay (3000);
  
}
