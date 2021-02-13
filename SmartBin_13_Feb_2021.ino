//Project Smart bin
//INDmakerspace Algorithm Factory

//karena menggunakan sensor ultrasonik maka ada 2 pin yaitu trigger dan echo
//jadi diskematik itu kan pin trigger sama pin echo nya beda yaitu :
//trigger pin 11
//echo pin 10

//woeee citt awkwk skematiknya dah ada di chat live-coding

// menambahkan library Servo
#include <Servo.h>

Servo servoku;
//made kami MAU MAKAN DULU YAAA :) tapi bohong 
//oiyaaa

#define trigpin 11
#define echopin 10
#define pinservo 9

int sudut = 0;
float jarak;
long durasi;
  
void setup()
{
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(pinservo, OUTPUT);
  delay(1000);
  servoku.attach(9);
  //kasih delay dikit biar gak langsung jalan atau indikator led kalau mau
  
}

void loop()
{
  //disini nanti perulangan untuk cek kondisi sensor dan menggerakan servo untuk membuka tong sampah
  hitungjarak();
  if(jarak <= 20)
  {
    for (sudut = 0; sudut <= 180; sudut += 1) 
    { 
      servoku.write(sudut);              
      delay(15);                      
    }
    delay(4000);
    
    for (sudut = 180; sudut >= 0; sudut -= 1) 
    { 
      servoku.write(sudut);             
      delay(15);                       
    }
  }
}

//membuat fungsi baru untuk membuat operasi perhitungan jarak dari sensor ultrasonikl
void hitungjarak()
{
  //blablablalblablalba 
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(8);
  
  durasi= pulseIn(echopin, HIGH);  // menerima suara ultrasonic
  jarak= (durasi/2) / 29.1;     // mengubah durasi menjadi jarak (cm)
  Serial.println(jarak);
}
