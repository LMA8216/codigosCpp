#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>
#include <Ultrasonic.h>

#define pinTrigger 2
#define pinEcho 3

RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
Ultrasonic ultrasonic(pinTrigger, pinEcho);

const uint16_t this_node = 02; // Address of our node in Octal format ( 04,031, etc)
const uint16_t master = 00;
float Dcm;
const unsigned long intervalo = 2000;
unsigned long ultEnvio;

int led12 = 1;

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);

}
void loop() {
  network.update();

  led12 = !led12;

  long microsec = ultrasonic.timing();
  Dcm = ultrasonic.convert(microsec, Ultrasonic::CM);

  unsigned long now = millis();
  if( (ultEnvio - now) >= intervalo){
  RF24NetworkHeader header2(master);
  bool ok = network.write(header2, &Dcm, sizeof(Dcm));
  ultEnvio = now;
  }
  delay(500);
}
