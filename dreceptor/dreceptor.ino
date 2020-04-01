/*
  StructEnviar

  Este programa muestra la decodificacion de tramas usando desplazamientos
  
  created 1 apr 2020
  by Fabian Astudillo-Salinas 
     <fabian.astudillos@ucuenca.edu.ec>
*/

#define FRAME_SIZE 3

uint8_t id;   // 8 bits
uint16_t temperatura; //9 bits
uint8_t humedad;  // 7 bits

uint8_t trama[FRAME_SIZE];

void setup() {
  Serial.begin(9600);
  memset(trama, 0, FRAME_SIZE);
  Serial3.begin(9600);
}

void loop() {
  int len = Serial3.readBytes(trama,FRAME_SIZE);
  if (len > 0) {
    id = trama[0];
    temperatura = ((uint16_t)trama[1]) << 1 | trama[2]>>7;
    humedad = trama[2] & B01111111;

    Serial.print(String(trama[0]));
    Serial.print("-");
    Serial.print(String(trama[1]));
    Serial.print("-");
    Serial.println(String(trama[2]));
  
    Serial.println(String(len));
    Serial.print("id:");
    Serial.println(id);
    Serial.print("temperatura:");
    Serial.println(temperatura);
    Serial.print("humedad:");
    Serial.println(humedad);
    Serial.println();
    
  }
}
