#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
#include <Ultrasonic.h>

#define pinTrigger 2
#define pinEcho 3

RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
Ultrasonic ultrasonic(pinTrigger, pinEcho);

const uint16_t this_node = 03; // Address of our node in Octal format ( 04,031, etc)
const uint16_t master = 00;

float Dcm;
const unsigned long intervalo = 2000;
unsigned long ultEnvio = 0 ;

int led = 1;

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  Serial.begin(9600);

}
void loop() {
  network.update();

  led = !led;
  
  long microsec = ultrasonic.timing();
  Dcm = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(Dcm);
  
  unsigned long now = millis();
  if( ultEnvio - now >= intervalo){ 
  RF24NetworkHeader header3(master);
  bool ok = network.write(header3, &Dcm, sizeof(Dcm));
  ultEnvio = now;
  }
  delay(500);
}
