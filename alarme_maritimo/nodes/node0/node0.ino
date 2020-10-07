#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define led_01 8 //verde
#define led_012 7//vermelho

//com4
RF24 radio(10, 9);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network

const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
const uint16_t node012 = 012;
const uint16_t node03 = 03;

const int buzzer = 7;
const int buzzer1 = 6;
float sinVal;
int toneVal;
void alarme_node1();
void alarme_node2();

int lamp =5;

void setup() {
  SPI.begin();

  Serial.begin(9600);
 

  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  //  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_012, OUTPUT);
  pinMode(lamp, OUTPUT);
}
void loop() {
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    float incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data

    if ( header.from_node == 1) {
      Serial.print("Ard. Nano = ");
      Serial.println(incomingData);
      if (incomingData < 30.0) {
        alarme_node1();
        digitalWrite(lamp, LOW);
      }
      else {
        noTone(buzzer);
        digitalWrite(lamp, HIGH);
      }
    }
    if ( header.from_node == 2) {
      Serial.print("Ard. Nano2 = ");
      Serial.println(incomingData);
      if (incomingData < 30.0) {
        alarme_node1();
        digitalWrite(lamp, LOW);
      }
      else {
        noTone(buzzer);
        digitalWrite(lamp, HIGH);
      }
    }
    if ( header.from_node == 3) {
      Serial.print("Ard. Nano3 = ");
      Serial.println(incomingData);
      if (incomingData < 30.0) {
        alarme_node1();
        digitalWrite(lamp, LOW);
      }
      else {
        noTone(buzzer);
        digitalWrite(lamp, HIGH);
      }
    }
  }
}

void alarme_node1() {
  for (int x = 0; x < 180; x++) {
    //converte graus para radianos, e depois obtém o valor do seno
    sinVal = (sin(x * (3.1416 / 180)));
    //gera uma frequência a partir do valor do seno
    toneVal = 2000 + (int(sinVal * 1000));
    tone(buzzer, toneVal);
    delay(2);
  }
}

void alarme_node2() {
  for (int x = 0; x < 180; x++) {
    //converte graus para radianos, e depois obtém o valor do seno
    sinVal = (sin(x * (3.1416 / 180)));
    //gera uma frequência a partir do valor do seno
    toneVal = 2000 + (int(sinVal * 1000));
    tone(buzzer1, toneVal);
    delay(2);
  }
}
/*
  //===== Sending =====//
  // Servo control at Node 01
  unsigned long potValue = analogRead(A0);
  unsigned long angleValue = map(potValue, 0, 1023, 0, 180); // Suitable for servo control
  RF24NetworkHeader header2(node01);     // (Address where the data is going)
  bool ok = network.write(header2, &angleValue, sizeof(angleValue)); // Send the data
  // LED Control at Node 012
  unsigned long buttonState = digitalRead(button);
  RF24NetworkHeader header4(node012);    // (Address where the data is going)
  bool ok3 = network.write(header4, &buttonState, sizeof(buttonState)); // Send the data
  // LEDs control at Node 022
  unsigned long pot2Value = analogRead(A1);
  RF24NetworkHeader header3(node022);    // (Address where the data is going)
  bool ok2 = network.write(header3, &pot2Value, sizeof(pot2Value)); // Send the data
  }
*/
