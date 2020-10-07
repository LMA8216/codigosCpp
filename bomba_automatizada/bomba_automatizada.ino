#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

#define DHTPIN A1

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
dht dht11;

float carga;
float condutividade;
float frequencia;
//volatile float freqMed = 0;
//float freqEf;
//int amostras = 3000;

void ler_freq_carga();
void ler_freq();

int lux = A0;
int bomba = 4;
int luminosidade;
int nivel = 12;
int estadoNivel;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);

pinMode(10, INPUT);
pinMode(bomba, OUTPUT);
pinMode(nivel, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ler_freq_carga();
  dht11.read11(A1);
  int h = int(dht11.humidity);
  int t = int(dht11.temperature);
  estadoNivel = digitalRead(nivel);
  luminosidade = analogRead(lux);
  Serial.println("carga: ");
  Serial.println(carga);
  Serial.println("luminosidade: ");
  Serial.println(luminosidade);
  Serial.println("condutividade: ");
  Serial.println(condutividade);
  Serial.println("tempera: ");
  Serial.println(t);
  Serial.println("nivel: ");
  Serial.println(estadoNivel);

  
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("T=");
  lcd.print(t);
  lcd.setCursor(5,0);
  lcd.print("h=");
  lcd.print(h);
  lcd.setCursor(10,0);
  lcd.print("R=");
  lcd.print(carga);
  lcd.setCursor(0,1);
  lcd.print("C=");
  lcd.print(condutividade);
  lcd.print("m");
  lcd.setCursor(8,1);
  lcd.print("Box=");
  lcd.print(estadoNivel ? "VOID" : "FULL");
 
  

  if((luminosidade > 700) && (estadoNivel == LOW)){
    digitalWrite(bomba, HIGH);
  }
  else{
    digitalWrite(bomba, LOW);
  }
  delay(500);

  
}

void ler_freq_carga(){
  unsigned long int periodo1 = pulseIn(10, HIGH);
  unsigned long int periodo2 = pulseIn(10, LOW);
  float periodoTotal = float(periodo1 + periodo2);
  frequencia = 100000/periodoTotal;
  carga = 1000000*(pow(frequencia,-1.137));
  condutividade = 1/(carga*0.001);
  //Serial.println(periodoTotal);
  
}

void ler_freq(){
  unsigned long int periodo1 = pulseIn(10, HIGH);
  unsigned long int periodo2 = pulseIn(10, LOW);
  float periodoTotal = float(periodo1 + periodo2);
  frequencia = 1000/periodoTotal;
}

/*for(int i=0; i<300; i++){
  unsigned long int periodo1 = pulseIn(10, HIGH);
  unsigned long int periodo2 = pulseIn(10, LOW);
  float periodoTotal = float(periodo1 + periodo2);
  frequencia = 1000/periodoTotal;
  freqMed = freqMed + frequencia;
  }

  freqEf = freqMed/amostras;
  carga = 9401.71*(pow(freqEf,-1.158));
  Serial.println(carga);
  delay(200);
  */
