//ROBOBUILDERS
// BLUETOOTH
#include <SoftwareSerial.h>
#include <VarSpeedServo.h>

#define pin_sev1   8  //garra abertura
#define pin_sev2   9   //garra gira(mão)
#define pin_sev3   10  //braço
#define pin_sev4   13  //base
#define pin_sev5A  11  //ante
#define pin_sev5B  12  //ante

SoftwareSerial seriall(7, 6); // RX, TX
VarSpeedServo servo1,servo2,servo3,servo4,servo5A,servo5B;

String voz;
bool espera = true;
int velocidade = 25;
int espaco;
String graus_str;
int graus;
int graus2;

void set_all_servos();
bool set_servo1();
bool set_servo2();
bool set_servo3();
bool set_servo4();
bool set_servo5A();
bool set_servo5B();
void set_mov_inicial();
void tchauzinho();
//void pega_stringBT();
//void format_stringBT();

//***************************************************SETUP*****************************************************************
void setup() {
  seriall.begin(9600);
  Serial.begin(9600);
  Serial.println("inicio da comunicação");

  set_all_servos();
  servo5A.write(90, velocidade);
  servo5B.write(90, velocidade);
  //set_mov_inicial();

}
//****************************************************LOOP******************************************************************

void loop() {
  while (seriall.available()){  
  delay(10); 
  char c = seriall.read(); 
  if (c == '#') {break;}
  voz += c; 
  } 
    
  if (voz.length() > 0) {
    
    Serial.println(voz);
    espaco = voz.indexOf(' ');
    graus_str = voz.substring(espaco);
    graus = graus_str.toInt();
    
    if((graus > 180) || (graus < 0)){
      graus = 90;
    }

    if(voz.substring(0,espaco) == "tchau"){
       tchauzinho();
    }
    if(voz.substring(0,espaco) == "velocidade"){
       velocidade = graus;
    }
    else if(voz.substring(0,espaco) == "garra"){
       servo1.write(graus, velocidade, espera);
    }
    else if(voz.substring(0,espaco) == "mão"){
       servo2.write(graus, velocidade, espera);
    }
    else if(voz.substring(0,espaco) == "braço"){
       servo3.write(graus, velocidade, espera);
    }
    else if(voz.substring(0,espaco) == "tronco"){
       graus2 = abs(180-graus);
       servo5A.write(graus, velocidade);
       servo5B.write(graus2, velocidade);
       
    }
    else if(voz.substring(0,espaco) == "base"){
       servo4.write(graus, velocidade, espera);
    }
  //  AQUI:
    voz="";
  }
} 

//******************************************************FUNÇÕES************************************************************************
void set_all_servos(){
  if(!set_servo1()){
    Serial.println("Servo1 não anexado");
  }
  
  if(!set_servo2()){
    Serial.println("Servo2 não anexado");
  }
  delay(10);
  if(!set_servo3()){
    Serial.println("Servo3 não anexado");
  }
  
  if(!set_servo4()){
    Serial.println("Servo4 não anexado");
  }
  
  if(!set_servo5A()){
    Serial.println("Servo5A não anexado");
  }
  
  if(!set_servo5B()){
    Serial.println("Servo5B não anexado");
  }
  else{
    Serial.println("Servos ok|");
  }
}

bool set_servo1(){

  bool sev1_ok_attach;
  
  pinMode(pin_sev1, OUTPUT);
  servo1.attach(pin_sev1);
  sev1_ok_attach = servo1.attached();

  return sev1_ok_attach;
  
}

bool set_servo2(){

  bool sev2_ok_attach;
  
  pinMode(pin_sev2, OUTPUT);
  servo2.attach(pin_sev2);
  sev2_ok_attach = servo2.attached();

  return sev2_ok_attach;
  
}

bool set_servo3(){

  bool sev3_ok_attach;
  
  pinMode(pin_sev3, OUTPUT);
  servo3.attach(pin_sev3);
  sev3_ok_attach = servo3.attached();

  return sev3_ok_attach;
  
}

bool set_servo4(){

  bool sev4_ok_attach;
  
  pinMode(pin_sev4, OUTPUT);
  servo4.attach(pin_sev4);
  sev4_ok_attach = servo4.attached();

  return sev4_ok_attach;
  
}

bool set_servo5A(){

  bool sev5A_ok_attach;
  
  pinMode(pin_sev5A, OUTPUT);
  servo5A.attach(pin_sev5A);
  sev5A_ok_attach = servo5A.attached();

  return sev5A_ok_attach;
  
}

bool set_servo5B(){

  bool sev5B_ok_attach;
  
  pinMode(pin_sev5B, OUTPUT);
  servo5B.attach(pin_sev5B);
  sev5B_ok_attach = servo5B.attached();

  return sev5B_ok_attach;
  
}

void set_mov_inicial(){

  servo1.write(90, velocidade, espera);
}

//**************************************************************ROTINAS***************************************************************8
void tchauzinho(){
  //tronco 120
  //braço  80
  //mao 80
  //garra 80
  //base 50
  // mao (120-40)
  servo4.write(50, velocidade);
  servo5A.write(120, velocidade);
  servo5B.write(80, velocidade);
  servo3.write(80, velocidade,espera);
  servo2.write(80, velocidade,espera);
  servo1.write(80, velocidade,espera);
  delay(500);

  for(int i=0; i<10; i++){
      servo2.write(120,velocidade,espera);
      servo2.write(40,velocidade,espera);
  }
}
