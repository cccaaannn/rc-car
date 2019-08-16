#include <IRremote.h>
#include <NewTone.h>


IRrecv irrecv(3);
decode_results result;

#define buzzerpin 13        //buzzerin + sı buraya - si gnd ye

#define yukari 0xFF18E7
#define asagi 0xFF4AB5
#define sol 0xFF10EF
#define sag 0xFF5AA5
#define orta 0xFF38C7
#define bir 0xFFA25D
#define iki 0xFF629D
#define uc 0xFFE21D 
#define yildiz 0xFF6897
#define sifir 0xFF9867

const int in1 = 9;
const int in2 = 10;
const int in3 = 11;
const int in4 = 8;
const int e1 = 5;
const int e2 = 6;


void setup() {

irrecv.enableIRIn();

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(e1,OUTPUT);
pinMode(e2,OUTPUT);

pinMode(buzzerpin,OUTPUT);

analogWrite(e1,70);
analogWrite(e2,70);
}



void loop() {


if(irrecv.decode(&result)){

  if(result.value == yukari){
    ileri_git();
  }
  if(result.value == asagi){
    geri_git();
  }
  if(result.value == sol){
   sola_don();
  }
  if(result.value == sag){
    saga_don();
  }
  if(result.value == orta){
    dur();
  }



  //1. vites
  if(result.value == bir){
    analogWrite(e1,70);
    analogWrite(e2,70);
  }
  
  //2. vites
  if(result.value == iki){
   analogWrite(e1,150);
   analogWrite(e2,150);
  }

  //3. vites
  if(result.value == uc){
   analogWrite(e1,255);
   analogWrite(e2,255);
  }


  if(result.value == sifir){
   kare();
  }



  //korna
  if(result.value == yildiz){
    korna();
  }


  
  irrecv.resume();
}
 
}



void kare(){

   ileri_git();
   
    delay(500);
   
   saga_don();
   
    delay(500);

   ileri_git();
    
    delay(500);

   saga_don();
    
    delay(500);

   ileri_git();
   
    delay(500);
   
   saga_don();
   
    delay(500);

   ileri_git();
    
    delay(500);

   saga_don();
    
    delay(500);

   dur();
   
}





//iki tekerde ileri
void ileri_git(){
    digitalWrite(in1,HIGH);
    digitalWrite(in3,LOW);

    digitalWrite(in2,HIGH);
    digitalWrite(in4,LOW);
}
//iki tekerde geri
void geri_git(){
    digitalWrite(in1,LOW);
    digitalWrite(in3,HIGH);

    digitalWrite(in2,LOW);
    digitalWrite(in4,HIGH);
}
//sol teker duruyo sağ teker ileri
void sola_don(){
    digitalWrite(in1,LOW);
    digitalWrite(in3,LOW);
    
    digitalWrite(in2,HIGH);
    digitalWrite(in4,LOW);
}
//sağ teker duruyo sol teker ileri
void saga_don(){
    digitalWrite(in2,LOW);
    digitalWrite(in4,LOW);
   
    digitalWrite(in1,HIGH);
    digitalWrite(in3,LOW);
}

//iki teker de duruyo
void dur(){
    digitalWrite(in1,LOW);
    digitalWrite(in3,LOW);

    digitalWrite(in2,LOW);
    digitalWrite(in4,LOW);
}




void korna(){
  NewTone(buzzerpin, 500); 
  delay(250);                     
  noNewTone(buzzerpin);   
  delay(250);

  NewTone(buzzerpin, 500); 
  delay(750);                     
  noNewTone(buzzerpin);   
  delay(750);
}
