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
  
  ![AUTOCAD](/twA109_1920-vehiculo-autonomo/autocad.PNG)
  
  Tras el diseño de las piezas en Autocad se pasó a su fabricación. Para llevarlas a la realidad se ha utilizado una impresora 3d, que a partir de un filamento de PLA, ha transformado un archivo .gcode en una pieza física. 
### Componentes electrónicos 
  El vehículo esta compuesto por diversos componentes electrónicos que se detallarán a continuación. Cabe remarcar que algunos componentes pueden verse variados debido al problema actual de abastecimiento.
  #### Arduino
  En primer lugar encontramos el arduino. Esta es la placa principal del proyecto y la encargada de coordinar el resto de componentes/sensores que constituyen el prototipo.
  Arduino UNO es un placa base electrónica, de hardware libre, formada principalmente por un microcontrolador y un entorno. Dicho microcontrolador es un ATmega328, chip de alto rendimiento desarrollado por Atmel. Está basado en un microprocesador de tipo RISC (reduced instruction set computer), los cuales son capaces de leer y escribir instrucciones simples. Funciona en un rango de 1.8 a 5.5 voltios, motivo por el cual existen otros elementos en la placa Arduino capaces de regular y estabilizar el voltaje de entrada. La placa Arduino dispone de 14 puertos de entrada y salida digitales, de los cuales 6 son de tipo PWM (pulse width modulation). Estos nos permiten enviar señales eléctricas mediante la modulación de pulso. Al igual que el resto de pines digitales, nos permite enviar señales de high o low, pero como peculiaridad, a través de estos podemos seleccionar el voltaje que queremos enviar de entre 0 y 5 voltios. Entre estos 14 pines encontramos también los RX y TX. Estos son los encargados de enviar y recibir información mediante la función “Serial.begin()”. En el caso de que el Arduino este conectado a un ordenador para la transmisión de información, estos pines no podrán ser conectados a ningún componente electrónico, ya que son los encargados de la comunicación entre la placa y el ordenador.   Situados en el lado contrario de la placa encontramos los pines analógicos junto a los de alimentación. Los pines analógicos son cinco, y van desde el A1 hasta el A5. Estos pueden actuar como pines digitales convencionales, pero además tienen la capacidad de enviar valores de entre 0 y 1023, permitiendo un mayor rango de actuación. El conjunto de pines de alimentación esta formado por tres de tipo GND, donde conectaremos los polos negativos de los componentes electrónicos empleados. Un pin 5v, al que conectaremos los elementos que queremos que estén continuamente alimentados por 5 voltios. Un pin 3.3v, cuyo funcionamiento es idéntico al de 5v, pero proporciona 3.3v. Por último encontramos el pin Vin, encargado de alimentar al Arduino cuando se le conecta una fuente externa de más de 5v. En este caso pasaría de alimentarse por el puerto usb a hacerlo por dicho pin.  Otros pines menos comunes son el AREF Y RESET, los encargados de referenciar el voltaje para los pines analógicos y resetear la placa respectivamente.  
Por otro lado encontramos el software , en concreto uno de tipo IDE (entorno de desarrollo 1 integrado). Este nos permite programar y ejecutar de una forma fácil y rápida.  La característica principal de este tipo de entornos es la capacidad que poseen de cubrir todo el ciclo de creación de un software. Esto quiere decir que son capaces de crear, modificar, compilar, depurar un software y construir interfaces gráficas (GUI),  consiguiendo así una gran efectividad. Para la programación de este tipo de placas únicamente es necesario el programa propio de Arduino. Este nos permite tanto desarrollar el código como compilarlo y subirlo a la placa para ser ejecutado. Uno de los grandes puntos a favor de este sistema es la gran comunidad que hay tras él, permitiéndote descargar librerías y programas que facilitan la tarea. 
  
  ![Arduino] (twA109_1920-vehiculo-autonomo/arduino.png)
  
#### L298N
Este componente es un driver dual basado en el chip L298N. Este te permite controlar dos motores de corriente continua (DC) o un motor bipolar. Cuenta, como la mayoría de los componentes, con sistemas de seguridad y diodos de protección, encargados de impedir que cargas superiores a las soportadas circulen por el componente. Incluye también un regulador de tipo LM7805, encargado de alimentar la parte lógica del módulo con 5v constantes. El módulo cuenta con cuatro salidas para los motores (OUT 1, OUT 2, OUT 3, OUT 4) a las cuales puedes conectar dos motores DC con sus respectivos positivos  y negativos, o bien cuatro motores DC, como es este caso. Para conectar estos cuatro motores, dos compartirán salidas, de forma que habrá que invertir la polaridad entre ellos para que el sentido de giro sea el mismo (Anexo 1). Después encontramos los pines de control. Estos se pueden dividir en pines de control de módulo ( IN1, IN2, IN3, IN4) y pines ENA y ENB. Estos segundos se conectaran al Arduino para variar la velocidad de los motores mediante la programación, o bien se les colocará un jumper de alimentación, de forma que la velocidad 2 no se podrá modificar. En cuanto a la alimentación, encontramos tres pines, +12v, GND, +5v. Gracias al regulador LM7805 integrado, encontramos dos posibles métodos de conexión: 
  - Con el jumper activado. Se podrán conectar voltajes de entre 6v y 12v al pin +12v. Como el jumper se encuentra activo, en el pin +5v obtendremos 5v de salida, que utilizaremos para alimentar el Arduino. 
  - Con el jumper desactivado. Se podrán conectar voltajes al pin +12v de entre 12v y 35v. Pero, a diferencia del método anterior, tendremos que alimentar la parte lógica del módulo conectándole 5v externos adicionales a través del pin +5v.
  
  ![L298N] (twA109_1920-vehiculo-autonomo/l298n.png)
 
 #### Servo
 
 
 


## Software

Desarrollo en C . Programación del microcontrolador a través del IDE de Arduino.


