// P101, electronic arts installation about the Olivetti Programma 101
// Roni Bandini, November 2024
// MIT License


#include <HT1621.h> 
#include <EEPROM.h>

HT1621 lcd; 

// Motor A
const int A1A = 2;
const int A1B = 3; 

long counter=0;
long randNumber;
int textDelay=2000;
int mouthDirection=0;



void fibo(){
      long fib1 = 0, fib2 = 1, fib3; 

      lcd.print(fib1);
      lcd.clear(); 
      delay(500);
      lcd.print(fib2);
      delay(500);
      lcd.clear(); 

      while (true) { 
        fib3 = fib1 + fib2; 
        if (fib3 > 999999) break; 
        lcd.print(fib2);
        fib1 = fib2; fib2 = fib3; 
        delay(100);
        lcd.clear(); 
      }

}

void mouth(){

  if (mouthDirection==0)
  { 
    motorA('R'); 
    mouthDirection=1;
  }
  else
  {
    motorA('L');     
    mouthDirection=0;
  }
  
}

void zeroTo999(){

for (long i = 0; i <= 999999; i=i+1000) {        
        lcd.print(i);
        delay(5);
        lcd.clear(); 
  }

}

void randomNumbers(){

  lcd.print("ERROR1");
  motorA('R'); 
  for (long i = 0; i <= 25; i++) {      
        randNumber = random(999999);  
        lcd.print(randNumber);
        delay(50);
        lcd.clear(); 
  }
  motorA('O'); 

}

void setup() {

  Serial.begin(115200);
 
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);    

  randomSeed(analogRead(0));
  
  // cs, wr, Data, backlight
  lcd.begin(13, 12, 7, 10); 
  lcd.noBacklight();
  lcd.clear();  
  
  mouth(); 
  printText("P101");
  delay(textDelay);

}

void printText(char* myText){
  lcd.print(myText);
  delay(textDelay);
  mouth();
}

void loop() {

  printText("ERROR");

  randomNumbers();  

  printText("Truth");
  printText("about");
  printText("P101");

  randomNumbers();
  
  printText("YR 7A8");
  printText("Adrian");
  printText("Oliuet");
  printText("train");
  printText("uas");
  printText("no");
  printText("acciden");

  randomNumbers();

  printText("YR 7A9");
  printText("Mario");
  printText("Tchou");
  printText("car");
  printText("uas");
  printText("no");
  printText("acciden");

  randomNumbers();

  printText("YR 7A9");
  printText("P101");
  printText("stolen");

  randomNumbers();

  printText("YR 7AC");
  printText("Hostil");
  printText("buy");

  randomNumbers();

  printText("P101");
  printText("used");
  printText("for");
  printText("Apollo");
  printText("and");
  printText("B52");

  zeroTo999();

  counter=counter+1;
     
}

void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
  }else{  
    // Turn motor OFF
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}// motorA end
