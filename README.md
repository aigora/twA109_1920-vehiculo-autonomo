# Título del trabajo

COCHE AUTÓNOMO

## Integrantes del equipo

Jorge López Montero, David Rodríguez Blanco, Cristina Navarro Bados.

## Objetivos del trabajo

•	El objetivo principal del trabajo es desarrollar un vehículo capaz de seguir una línea de forma autónoma cabeceando lo mínimo posible.

## Hardware

Dentro del hardware podemos diferenciar dos secciones principales, el chasis y los componentes electrónicos. 

### Chasis
  El chasis del vehículo ha sido diseñado utilizando el programa Autocad. La principal ventaja que presenta frente a otros programas es la capacidad de dibujar vectorialmente, lo que nos permite realizar diseños muy exactos, desarrollando piezas que encajaran milimétricamente eliminando cualquier futura holgura o mal ajuste entre las piezas y componentes.
  Para facilitar la fabricación del prototipo se han ido diseñando las distintas partes individualmente como se puede observar en la siguiente imagen.
  
  ![AUTOCAD](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/autocad.PNG)
  
  Una vez todas las piezas fueron diseñadas e impresas, el siguiente paso fue la base que las une. Para su diseño se tuvo en cuenta las limitaciones (dimensionalmente hablando) de la impresora, y se utilizaron las medidas de las piezas anteriores. 
  
  ![Base](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/7.jpeg)
  
  En esta base se soportan las distintas piezas mediante tornillos. En la parte inferior de la base se han incluido orificios de la medida exacta de las tuercas utilizadas con el fin de facilitar su montaje.
  Con todas las piezas del chasis disponibles, se procedió a su montaje, obteniendo el resultado mostrado a continuación. 
  
  ![Chasis](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/6.jpeg)
  
  Tras esto, el siguiente paso consiste en ensamblar todos los componentes electrónicos. Para ello, y con le fin de simplificar en la medida de lo posible las conexiones para solventar con facilidad futuros problemas así como mejorar el resultado final, todas las resistencias necesarias, conexiones entre componentes, etc, se han realizado en la placa mostrada.
  
  ![Placa soldaduras](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/5.jpeg)
  
  Esta se conecta con el arduino mediante unos pines que están soldados en su parte inferior y, a su vez, a la placa se conectan los componentes restantes (L298N, LCD, servo) gracias a los pines superiores que se observan en la imagen. 
  Con todos los componentes montados e interconectados el resultado final obtenido es: 
  
  ![Coche1](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/1.jpeg)
  ![Coche2](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/2.jpeg)
  ![Coche3](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/3.jpeg)
  ![Coche4](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/4.jpeg)
  
### Componentes electrónicos 
  El vehículo esta compuesto por diversos componentes electrónicos que se detallarán a continuación. Cabe remarcar que algunos de ellos pueden verse variados debido al problema actual de abastecimiento.
#### Arduino
 En primer lugar encontramos el arduino. Esta es la placa principal del proyecto y la encargada de coordinar el resto de componentes/sensores que constituyen el prototipo.
  Arduino UNO es un placa base electrónica, de hardware libre, formada principalmente por un microcontrolador y un entorno. Dicho microcontrolador es un ATmega328, chip de alto rendimiento desarrollado por Atmel. Está basado en un microprocesador de tipo RISC (reduced instruction set computer), los cuales son capaces de leer y escribir instrucciones simples. Funciona en un rango de 1.8 a 5.5 voltios, motivo por el cual existen otros elementos en la placa Arduino capaces de regular y estabilizar el voltaje de entrada. La placa Arduino dispone de 14 puertos de entrada y salida digitales, de los cuales 6 son de tipo PWM (pulse width modulation). Estos nos permiten enviar señales eléctricas mediante la modulación de pulso. Al igual que el resto de pines digitales, nos permite enviar señales de high o low, pero como peculiaridad, a través de estos podemos seleccionar el voltaje que queremos enviar de entre 0 y 5 voltios. Entre estos 14 pines encontramos también los RX y TX. Estos son los encargados de enviar y recibir información mediante la función “Serial.begin()”. En el caso de que el Arduino este conectado a un ordenador para la transmisión de información, estos pines no podrán ser conectados a ningún componente electrónico, ya que son los encargados de la comunicación entre la placa y el ordenador.  
  Situados en el lado contrario de la placa encontramos los pines analógicos junto a los de alimentación. Los pines analógicos son cinco, y van desde el A1 hasta el A5. Estos pueden actuar como pines digitales convencionales, pero además tienen la capacidad de enviar valores de entre 0 y 1023, permitiendo un mayor rango de actuación. El conjunto de pines de alimentación esta formado por tres de tipo GND, donde conectaremos los polos negativos de los componentes electrónicos empleados. Un pin 5v, al que conectaremos los elementos que queremos que estén continuamente alimentados por 5 voltios. Un pin 3.3v, cuyo funcionamiento es idéntico al de 5v, pero proporciona 3.3v. Por último encontramos el pin Vin, encargado de alimentar al Arduino cuando se le conecta una fuente externa de más de 5v. En este caso pasaría de alimentarse por el puerto usb a hacerlo por dicho pin.  Otros pines menos comunes son el AREF Y RESET, encargados de referenciar el voltaje para los pines analógicos y resetear la placa respectivamente.  
  Por otro lado encontramos el software , en concreto uno de tipo IDE (entorno de desarrollo 1 integrado). Este nos permite programar y ejecutar de una forma fácil y rápida.  La característica principal de este tipo de entornos es la capacidad que poseen de cubrir todo el ciclo de creación de un software. Esto quiere decir que son capaces de crear, modificar, compilar, depurar un software y construir interfaces gráficas (GUI),  consiguiendo así una gran efectividad. Para la programación de este tipo de placas únicamente es necesario el programa propio de Arduino. Este nos permite tanto desarrollar el código como compilarlo y subirlo a la placa para ser ejecutado. Uno de los grandes puntos a favor de este sistema es la gran comunidad que hay tras él, permitiéndote descargar librerías y programas que facilitan la tarea. 
  
  ![Arduino](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/arduino.png)
  
#### L298N
Este componente es un driver dual basado en el chip L298N. Permite controlar dos motores de corriente continua (DC) o un motor bipolar. Cuenta, como la mayoría de los componentes, con sistemas de seguridad y diodos de protección, encargados de impedir que cargas superiores a las soportadas circulen por el componente. Incluye también un regulador de tipo LM7805, encargado de alimentar la parte lógica del módulo con 5v constantes. El módulo cuenta con cuatro salidas para los motores (OUT 1, OUT 2, OUT 3, OUT 4) a las cuales puedes conectar dos motores DC con sus respectivos positivos  y negativos. 
  Tras estos encontramos los pines de control. Se pueden dividir en pines de control de módulo ( IN1, IN2, IN3, IN4) y pines ENA y ENB. Estos segundos se conectaran al Arduino para variar la velocidad de los motores mediante la programación, o bien se les colocará un jumper de alimentación, de forma que la velocidad no se podrá modificar. 
  En cuanto a la alimentación, encontramos tres pines, +12v, GND, +5v. Gracias al regulador LM7805 integrado, encontramos dos posibles métodos de conexión: 
  - Con el jumper activado. Se podrán conectar voltajes de entre 6v y 12v al pin +12v. Como el jumper se encuentra activo, en el pin +5v obtendremos 5v de salida, que utilizaremos para alimentar el Arduino. 
  - Con el jumper desactivado. Se podrán conectar voltajes al pin +12v de entre 12v y 35v. Pero, a diferencia del método anterior, tendremos que alimentar la parte lógica del módulo conectándole 5v externos adicionales a través del pin +5v.
  
  ![L298N](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/l298n.png)
 
#### Micro servo SG90
Micro servo SG90 es un servo miniatura de reducidas dimensiones y bajo consumo. El servo SG90 tiene un conector universal tipo “S” que encaja perfectamente en la mayoría de los receptores de radio control incluyendo los Futaba, JR, GWS, Cirrus, Hitec y otros. Los cables en el conector están distribuidos de la siguiente forma: Rojo = Alimentación (+), Marrón= Alimentación (-) o tierra, Naranja= Señal PWM.

Tiene unas dimensiones de 22 X 11.5 X 27 mm, trabaja con tensiones de entre 4 V a 7.2V con una velocidad de giro de 60 grados de 0.12 s y además es compatible con tarjetas como Arduino, la cual utilizaremos para nuestro proyecto. Los servos que incorporemos a este proyecto se dedicaran a mantener el coche en la línea trazada, así cuando los sensores detecten que el automóvil se sale de la línea ya sea por que haya un giro o cualquiera otra cosa, el servo posicionará correctamente al automóvil.
 
   ![Servo](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/servo.jpg)
   
 #### CNY70
 El CNY70 es el tipo de senso óptico reflectivo que utilizaremos en nuestro proyecto. El CNY70 es un sensor que incluye un led infrarrojo y un fototransistor. Lo emplearemos para Arduino como detector de líneas. Su función principal es la de medir la reflexión en superficies. El circuito integrado tiene cuatro pines, (1) y (2) son para el led emisor. También los pines (3) y (4) son para el fototransistor. Para poder hacer una detección se requiere entonces de una superficie que refleje la luz infrarroja.
Dado que en nuestro proyecto lo utilizaremos como detector de líneas, si la superficie reflectora es negra, no se reflejará tanta luz con longitud de onda en el infrarrojo y por lo tanto tendremos un ‘0’ a la salida del emisor del fototransistor. Si por el contrario tenemos que el sensor está «viendo» una superficie blanca, tendremos un ‘1’. FUNCIONAMIENTO DEL CNY70 El CNY70 funciona como un detector de distancia. Para esto, requiere de una superficie que pueda reflejar la luz infrarroja. Entonces el detector recibe esta luz en la base del fototransistor. Si la corriente en la base es suficiente, permite el paso de corriente entre el colector y el emisor. El CNY70 funciona como un switch que se abre o cierra si existe una superficie que refleje la señal que emite el diodo IR. Distancia máxima del CNY70 En el CNY70 la distancia máxima la determina la corriente que le llega a la base del transistor. La distancia va desde 0mm hasta 10mm. La corriente de la base depende de la corriente que se le suministre al diodo emisor. Para calcular la resistencia del led, se usa la Ley de ohm. Entonces la fórmula que aplica es la siguiente.
Corriente CNY70, I = V/R
Es decir que la corriente depende de la razón del voltaje y la resistencia. El voltaje de 1.25V es el voltaje de caída del diodo emisor. Este valor depende de cada CNY70 y puede ir desde 1.25V hasta 1.6V. ARDUINO Para usar el CNY70 con Arduino podemos hacerlo funcionar de dos formas: digitalmente (0,1) para distancias de 0 a 10mm. Y la segunda forma es con una entrada analógica y midiendo la señal que proporciona el sensor dependiendo de la situación que se desee.
 
 ![CNY70](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/CNY70.jpg)
 
 #### LCD
 Para este proyecto se ha empleado un actuador LCD ( Liquid Cristal Display ) como elemento output para mostrar información sin necesidad de utilizar un monitor serial, es decir, sin necesidad de tenerlo conectado a un ordenador. El funcionamiento de este LCD se basa en las propiedades de la luz polarizada . A partir de una serie de filtros y la iluminación de fondo podemos ver la información mostrada en la pantalla.  La luz de fondo se produce en la parte inferior del monitor. 
 El panel superior está formado por varias capas. En los extremos encontramos dos filtros polarizados orientados en un ángulo de 90º entre si. El filtro superior transforma la luz no polarizada en polarizada de un solo plano. Esta luz no puede superar el filtro inferior porque, como ya se ha mencionado anteriormente, se encuentra girado 90º. Para conseguir que vuelva a rotar se coloca un cristal líquido intermedio. Este cristal gracias a sus moléculas internas consigue girar el ángulo de la luz. A su vez, el cristal posee unas capas de alineación en su parte superior e inferior, que son las encargadas de girar las moléculas del cristal con un ángulo concreto.  
Todo este conjunto está recubierto por una capa de electrodos transparentes, cuya función es ajustar el plano de polarización y con ello la intensidad de la luz. En función de la tensión que reciben girará con más o menos ángulo las moléculas del cristal, variando la intensidad. Una vez este conjunto está formado se le coloca un filtro para poder ajustar la tonalidad de luz deseada.

![LCD](https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/LCD.jpg)

## Software
El software se va a desarrollar a través del IDE de Arduino. 
Como punto de inicio se han desarrollado programas individuales para los distintos componentes con el fin de obtener los parámetros necesarios para la futura programación definitiva.

Comenzamos con el driver controlador del motor L298N.
    
        // Motor 
     // Declaramos los pines a los que esta conectado el l298N
    int ENA = 11; 
    int IN1 = 13;
    int IN2 = 12;


    void setup ()
    {
     // Declaramos todos los pines como salidas
    pinMode (ENA, OUTPUT);
    pinMode (IN1, OUTPUT);
    pinMode (IN2, OUTPUT);
    }

    void loop ()
    {
     //Direccion motor A
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 150); //Velocidad motor A
    }

Con este sencillo programa, lo que se ha conseguido es verificar el correcto funcionamiento tanto del motor como del driver, así como confirmar que los pines escogidos son válidos. 
En un primer lugar declaramos los pines utilizados, para más adelante declararlos como salida, ya que solo recibiran información.
En el void loop del programa se determina el sentido de giro mediante los pines IN1 y IN2. Sin embargo lo que conseguimos mediante el ENA es variar la velocidad de giro del motor. El valor utilizado en el programa anterior es orientativo, ya que será necesario tener el modelo completamente contruido para poder realizar pruebas y determinar el valor que mejor se ajuste a las necesidades.

Programación de prueba del lcd.

    #include <LiquidCrystal.h>

    LiquidCrystal lcd(8,2,4,5,6,7); // Pineas a los que esta conectado el lcd
    int V0=9; //Pin encargado de regular el contraste del lcd
    int i=0;

    void setup() {

     analogWrite(V0,120); //Contraste
  
      lcd.begin(16,2); //Definimos que las dimensiones de la pantalla es de 16x2

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
    }

    void loop() {
    }

Con este programa, al igual que con el anterior y el que viene a continuación, verificamos el correcto funcionamiento del componente, en este caso el lcd.
Como se puede observar, primeramente declaramos la librería que vamos a utilizar, lo que nos permite simplificar en gran medida nuestro programa. A continuación declaramos los pines a los que está conectado el lcd, el pin encargado de regular el voltaje y definimos una variable de tipo entero que será utilizada en futuros bucles.
Este programa ha sido desarrollado en su totalidad en el void setup(), ya que queremos que solo sea mostrado al iniciar el programa. Nos mostrará una serie de indicaciones que debemos seguir para la correcta configuración del prototipo.
En un futuro, cuando se anexionen todos los subprogramas que están siendo explicados, esta sección será definida en una función independiente, con el fin de simplificar el programa final y facilitar posibles arreglos o modificaciones. 
A su vez se pretende incluir una función capaz de medir, en tiempo real, el voltaje de la batería, que será mostrado a través del lcd permitiéndonos conocer el momento preciso de recarga de la bateria sin necesidad de conectar cualquier otro dispositivo externo. 

Finalemente, el último programa que se ha podido desarrollar (debido a la falta de componentes) es el que implica el servo. El objetivo de este programa era conocer los valores de ángulo máximo y mínimo que el prototipo admite, así como el ángulo correcto para que el coche se desplace lo más recto posible. Obviamente estos valores nos son definitivos, pero sí que serán bastente útiles para poder continuar con el correcto desarrollo del resto de programa. 

    #include <Servo.h>
    #define CEN 100
    #define MIN 130
    #define MAX 70
 
    Servo myservo;  // crea el objeto servo
 
    int pos = 0;    // posicion del servo
 
    void setup() {
       myservo.attach(10);  // vincula el servo al pin digital 9
       myservo.write(CEN);
       delay(2000);
      myservo.write(MIN);
      delay(2000);
      myservo.write(MAX);
      delay(2000);
       myservo.write(CEN);
       delay(2000);
    }
 
    void loop() {
    }
    
Una vez más se ha empleado una librería predefinida con el mismo fin que en anteriores programas.
Este programa nos permite ir variando de forma manual el ángulo de giro hasta conseguir el deseado.
Al principio del mismo se ha incluido la libreria, así como se han definido los valores de centro, ángulo máximo y ángulo mínimo. A continuación se crea el objeto, se define la variable a utilizar y se comienza con el void setup. Al igual que se ha visto en programas anteriores, solo se emplea el void setup ya que únicamente nesitamos realizar pequeñas pruebas de forma manual y sencilla. Este programa comienza centrando las ruedas, para más tarde girarlas a ambos lados comprobando los ángulos máximos. 

Cabe destacar que en un futuro todos estos subprogramas serán definidos en funciones independientes que serán llamadas por la función principal cuando así sea determiando. 

Debido a la posibilidad de que los sensores CNY70 no lleguen a tiempo, se ha desarrollado un programa con el fin de mostrar que el resto de componentes funcionan de forma correcta. En cualquier caso, como se puede observar en la imágen de la placa, todas las resistencias, conectores y demás elementos necesarios para la utilización de estos sensores han sido preinstalados con el fin de completar el prototipo en el menor tiempo posible. 

   https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/Demostraci%C3%B3n.ino)
   
 EL correcto funcionamiento de este código será mostrado en el futuro video a entregar. 
 
 En un principio, y sin conocer si los sensores llegarían a tiempo, se desarrollo un programa independiente encargado de leer la información procedente de los sensores. Este es el denominado "Código 2".
 Pero finalemente, con los sensores disponibles, se procedió a unificar el código para cargarlo más tarde en el arduino. Tras realizar diversas pruebas con todos los códigos independientes de los que disponiamos, se tomó la decisión de llevar a cabo en modificación en la sección encargada de reconocer la línea. De esta forma, el código definitivo es: 
 
  https://github.com/aigora/twA109_1920-vehiculo-autonomo/blob/master/V.2.ino)
 


