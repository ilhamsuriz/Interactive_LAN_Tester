#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int clockPin = 8;
int latchPin = 9;
int dataPin = 10;
byte pinOut = 0;
int outPin = 0;

int Lo1 = 0;
int Lo2 = 0;
int Lo3 = 0;
int Lo4 = 0;
int Lo5 = 0;
int Lo6 = 0;
int Lo7 = 0;
int Lo8 = 0;
int cable = 0;
int eth1 = 0;
int eth2 = 0;
int eth3 = 0;
int eth4 = 0;
int eth5 = 0;
int eth6 = 0;
int eth7 = 0;
int eth8 = 0;

int ethIn1 = 12;
int ethIn2 = 11;
int ethIn3 = 14;
int ethIn4 = 15;
int ethIn5 = 16;
int ethIn6 = 17;
int ethIn7 = 18;
int ethIn8 = 19;

int test = 0;
int verify = 0;

void setup() {
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("*- INTERAKTIF -*");
    delay(750);
    lcd.setCursor(0,1);
    lcd.print("*- LAN TESTER -*");
    delay(3000);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("XII TKJ 01");
    delay(750);
    lcd.setCursor(0,1);
    lcd.print("SMK N 1 ADIWERNA");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Absen : ");
    delay(750);
    lcd.setCursor(0,1);
    lcd.print("0");
    delay(200);
    lcd.setCursor(1,1);
    lcd.print("7");
    delay(200);
    lcd.setCursor(2,1);
    lcd.print(",");
    delay(200);
    lcd.setCursor(3,1);
    lcd.print(" ");
    delay(200);
    lcd.setCursor(4,1);
    lcd.print("1");
    delay(200);
    lcd.setCursor(5,1);
    lcd.print("6");
    delay(200);
    lcd.setCursor(6,1);
    lcd.print(",");
    delay(200);
    lcd.setCursor(7,1);
    lcd.print(" ");
    delay(200);
    lcd.setCursor(8,1);
    lcd.print("2");
    delay(200);
    lcd.setCursor(9,1);
    lcd.print("1");
    delay(200);
    lcd.setCursor(10,1);
    lcd.print(",");
    delay(200);
    lcd.setCursor(11,1);
    lcd.print(" ");
    delay(200);
    lcd.setCursor(12,1);
    lcd.print("3");
    delay(200);
    lcd.setCursor(13,1);
    lcd.print("1");
    delay(3000);
    lcd.clear();
    
    Serial.begin(9600);
    
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    
    pinOut = 0;
     
    pinMode(ethIn1, INPUT);
    pinMode(ethIn2, INPUT);
    pinMode(ethIn3, INPUT);
    pinMode(ethIn4, INPUT);
    pinMode(ethIn5, INPUT);
    pinMode(ethIn6, INPUT);
    pinMode(ethIn7, INPUT);
    pinMode(ethIn8, INPUT);
}

void loop() {
    Serial.print("---------- STARTING ----------"); 
    cable = 0;
    Lo1 = 0;
    Lo2 = 0;
    Lo3 = 0;
    Lo4 = 0;
    Lo5 = 0;
    Lo6 = 0;
    Lo7 = 0;
    Lo8 = 0;
    
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Starting");
    lcd.setCursor(3,1);
    lcd.print("Processing");
    delay(1500);
    lcd.clear();
    lcd.print("In  : ");
    lcd.setCursor(0,1);
    lcd.print("Out : ");
    
    outPin = 0;
    
    for (int outPin = 0; outPin <= 7; outPin++) {
    delay(250);
    
    pinOut = 0;
    
    bitSet(pinOut, outPin);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, pinOut);
    digitalWrite(latchPin, HIGH);
  
    int eth1 = digitalRead(ethIn1);
    int eth2 = digitalRead(ethIn2);
    int eth3 = digitalRead(ethIn3);
    int eth4 = digitalRead(ethIn4);
    int eth5 = digitalRead(ethIn5);
    int eth6 = digitalRead(ethIn6);
    int eth7 = digitalRead(ethIn7);
    int eth8 = digitalRead(ethIn8);
    
    Serial.println();
    Serial.print("Port verification status : ");
    Serial.print(eth1);
    Serial.print(eth2);
    Serial.print(eth3);
    Serial.print(eth4);
    Serial.print(eth5);
    Serial.print(eth6);
    Serial.print(eth7);
    Serial.print(eth8);
    
    if (eth1 == 1) {
      verify = 1;
    }
    else {
      if (eth2 == 1) {
        verify = 2;
      }
      else {
        if (eth3 == 1) {
           verify = 3;
        }
        else {
           if (eth4 == 1) {
             verify = 4;
           }
           else {
             if (eth5 == 1) {
               verify = 5;
             }
             else {
               if (eth6 == 1) {
                 verify = 6;
               }
               else {
                 if (eth7 == 1) {
                   verify = 7;
                 }
                 else {
                   if (eth8 == 1) {
                     verify = 8;
                   }
                   else {
                     
                   }
                 }
               }
             }
           }
         }
       }                               
     }
                                             
    lcd.setCursor(outPin+6,0);
    lcd.print(outPin+1);
    lcd.setCursor(outPin+6,1);
    lcd.print(verify);
    verify = 0l;
    }
    delay(3000);
   
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Starting");
    lcd.setCursor(2,1);
    lcd.print("Verification");
    delay(1500);
    
    for (int outPin = 0; outPin <= 7; outPin++) {
    Serial.println();
    Serial.print("Pin out : ");
    Serial.print(outPin);
    
    pinOut = 0;
    
    bitSet(pinOut, outPin);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, pinOut);
    digitalWrite(latchPin, HIGH);
 
    int eth1 = digitalRead(ethIn1);
    int eth2 = digitalRead(ethIn2);
    int eth3 = digitalRead(ethIn3);
    int eth4 = digitalRead(ethIn4);
    int eth5 = digitalRead(ethIn5);
    int eth6 = digitalRead(ethIn6);
    int eth7 = digitalRead(ethIn7);
    int eth8 = digitalRead(ethIn8);
    int test = analogRead(ethIn1);
  
    if (outPin == 0 && eth1 == 1) {
      Lo1 = 1;
    }
    else {
      if (outPin == 0 && eth3 == 1) {
        Lo1 = 256;
      }
    }
           
    if (outPin == 1 && eth2 == 1) {
      Lo2 = 2;
    }
    else {
      if (outPin == 1 && eth6 == 1) {
        Lo2 = 512;
      }
    }
        
    if (outPin == 2 && eth3 == 1) {
      Lo3 = 4;
    }
    else {
      if (outPin == 2 && eth1 == 1) {
        Lo3 = 768;
      }
    }
            
    if (outPin == 3 && eth4 == 1) {
      Lo4 = 8;
    }
    else {
      
    }
          
    if (outPin == 4 && eth5 == 1) {
      Lo5 = 16;
    }
    else {
      
    }
            
    if (outPin == 5 && eth6 == 1) {
      Lo6 = 32;
    }
    else {
      if (outPin == 5 && eth2 == 1) {
        Lo6 = 1256;
      }
    }
        
    if (outPin == 6 && eth7 == 1) {
      Lo7 = 64;
    }
    else {
      
    }
            
    if (outPin == 7 && eth8 == 1) {
      Lo8 = 128;
    }
    else {
      
    }
    
    Serial.println();
    Serial.print("Port reading status : ");
    Serial.print(eth1);    
    Serial.print(eth2);   
    Serial.print(eth3);
    Serial.print(eth4);
    Serial.print(eth5);
    Serial.print(eth6);
    Serial.print(eth7);
    Serial.print(eth8);  
      
    cable = Lo1 + Lo2 + Lo3 + Lo4 + Lo5 + Lo6 + Lo7 + Lo8;
      
    Serial.println();
    Serial.print("Number values found : ");
    Serial.print(cable);
    }
      
    if (cable == 255) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Done, it works!");
      delay(500);
      lcd.setCursor(0,1);
      lcd.print("S");
      delay(100);
      lcd.setCursor(1,1);
      lcd.print("t");
      delay(100);
      lcd.setCursor(2,1);
      lcd.print("r");
      delay(100);
      lcd.setCursor(3,1);
      lcd.print("a");
      delay(100);
      lcd.setCursor(4,1);
      lcd.print("i");
      delay(100);
      lcd.setCursor(5,1);
      lcd.print("g");
      delay(100);
      lcd.setCursor(6,1);
      lcd.print("h");
      delay(100);
      lcd.setCursor(7,1);
      lcd.print("t");
      delay(100);
      lcd.setCursor(8,1);
      lcd.print(" ");
      delay(100);
      lcd.setCursor(9,1);
      lcd.print("c");
      delay(100);
      lcd.setCursor(10,1);
      lcd.print("a");
      delay(100);
      lcd.setCursor(11,1);
      lcd.print("b");
      delay(100);
      lcd.setCursor(12,1);
      lcd.print("l");
      delay(100);
      lcd.setCursor(13,1);
      lcd.print("e");
      delay(100);
      lcd.setCursor(14,1);
      lcd.print(".");
      delay(3000);
      }
    else {
      if (cable == 3008) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Done, it works!");
        delay(500);
        lcd.setCursor(0,1);
        lcd.print("C");
        delay(100);
        lcd.setCursor(1,1);
        lcd.print("r");
        delay(100);
        lcd.setCursor(2,1);
        lcd.print("o");
        delay(100);
        lcd.setCursor(3,1);
        lcd.print("s");
        delay(100);
        lcd.setCursor(4,1);
        lcd.print("s");
        delay(100);
        lcd.setCursor(5,1);
        lcd.print(" ");
        delay(100);
        lcd.setCursor(6,1);
        lcd.print("c");
        delay(100);
        lcd.setCursor(7,1);
        lcd.print("a");
        delay(100);
        lcd.setCursor(8,1);
        lcd.print("b");
        delay(100);
        lcd.setCursor(9,1);
        lcd.print("l");
        delay(100);
        lcd.setCursor(10,1);
        lcd.print("e");
        delay(100);
        lcd.setCursor(11,1);
        lcd.print(".");
        delay(3000);
      }
      else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Fail, try again!");
        delay(500);
        lcd.setCursor(0,1);
        lcd.print("U");
        delay(100);
        lcd.setCursor(1,1);
        lcd.print("n");
        delay(100);
        lcd.setCursor(2,1);
        lcd.print("k");
        delay(100);
        lcd.setCursor(3,1);
        lcd.print("n");
        delay(100);
        lcd.setCursor(4,1);
        lcd.print("o");
        delay(100);
        lcd.setCursor(5,1);
        lcd.print("w");
        delay(100);
        lcd.setCursor(6,1);
        lcd.print("n");
        delay(100);
        lcd.setCursor(7,1);
        lcd.print(" ");
        delay(100);
        lcd.setCursor(8,1);
        lcd.print("c");
        delay(100);
        lcd.setCursor(9,1);
        lcd.print("a");
        delay(100);
        lcd.setCursor(10,1);
        lcd.print("b");
        delay(100);
        lcd.setCursor(11,1);
        lcd.print("l");
        delay(100);
        lcd.setCursor(12,1);
        lcd.print("e");
        delay(100);
        lcd.setCursor(13,1);
        lcd.print(".");
        delay(3000);
      }
   }
}
