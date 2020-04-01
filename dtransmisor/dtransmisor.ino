/*
  sreceptor

  Este programa muestra la codificacion de tramas usando desplazamientos

  created 1 Apr 2020
  by Fabian Astudillo-Salinas 
     <fabian.astudillos@ucuenca.edu.ec>
*/

#define FRAME_SIZE 3

uint8_t id;				// 8 bits
uint16_t temperatura;	// 9 bits
uint8_t humedad;		// 7 bits

uint8_t trama[FRAME_SIZE];

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  /*Realizar la adquisicion de datos*/
  id = 1;
  temperatura = 400;
  humedad = 50;
  trama[0] = id;
  trama[1] = (uint8_t)(temperatura >> 1);
  trama[2] = ((uint8_t)temperatura << 7) | (humedad & B01111111);
  Serial3.write(trama, FRAME_SIZE);
  Serial.println("Transmitting");
  Serial.print(String(trama[0]));
  Serial.print("-");
  Serial.print(String(trama[1]));
  Serial.print("-");
  Serial.println(String(trama[2]));

  delay(1000);
}
