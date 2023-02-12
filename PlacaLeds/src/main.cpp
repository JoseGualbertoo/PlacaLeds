#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string.h>
#define TIMEOUT 5000 // mS
#define LED 13
SoftwareSerial mySerial(7, 6); // RX, TX

#define DATA 2   // Define DATA como 2
#define LATCH 3  // Define LATCH como 3
#define CLOCK 4  // Define CLOCK como 4
int formato_A[] = {
  0b00001100,  // **
  0b00110010,  //*  *
  0b01010010,  //*  *
  0b01111110,  //****
  0b10010010,  //*  *
  0b10110010,  //*  *
  0b11010010   //*  *
};

int formato_B[] = {
                   0b00011110, //***
                   0b00110010, //*  *
                   0b01010010, //*  *
                   0b01111110, //****
                   0b10010010, //*  *
                   0b10110010, //*  *
                   0b11011110  //***
                };

int formato_C[] = {
                   0b00001110, // ***
                   0b00110000, //*
                   0b01010000, //*
                   0b01110000, //*
                   0b10010000, //*
                   0b10110000, //*
                   0b11010000  // ***
                };

int formato_D[] = {
                   0b00011110, //***
                   0b00110010, //*  *
                   0b01010010, //*  *
                   0b01110010, //*  *
                   0b10010010, //*  *
                   0b10110010, //*  *
                   0b11011110  //***
                };

int formato_E[] = {
                   0b00011110, //****
                   0b00110000, //*
                   0b01010000, //*
                   0b01111110, //****
                   0b10010000, //*
                   0b10110000, //*
                   0b11011110  //****
                };

int formato_F[] = {
                  0b00011110,  //****
                  0b00110000,  //*
                  0b01010000,  //*
                  0b01111110,  //****
                  0b10010000,  //*
                  0b10110000,  //*
		  0b11010000   //*
                };

int formato_G[] = {
                   0b00011110, //****
                   0b00110000, //*
                   0b01010000, //*
                   0b01110111, //* ***
                   0b10010010, //*  *
                   0b10110010, //*  *
                   0b11011110  //****
                };

int formato_H[] = {
                   0b00010010, //*  *
                   0b00110010, //*  *
                   0b01010010, //*  *
                   0b01111110, //****
                   0b10010010, //*  *
                   0b10110010, //*  *
                   0b11010010  //*  *
                };

 int formato_I[] = {
                   0b00000100, //  *  
                   0b00100100, //  *  
                   0b01000100, //  *   
                   0b01100100, //  *   
                   0b10000100, //  *   
                   0b10100100, //  *   
                   0b11000100  //  *   
                };

int formato_J[] = {
                   0b00011110, //****
                   0b00100100, //  * 
                   0b01000100, //  *
                   0b01100100, //  *
                   0b10000100, //  *
                   0b10100100, //  *
                   0b11011100  //***
                };

int formato_K[] = {   
                   0b00010010,  //*  * 
                   0b00110010,  //*  *  
                   0b01010100,  //* *   
                   0b01111000,  //*     
                   0b10010100,  //* *   
                   0b10110010,  //*  *   
                   0b11110010   //*  * 
       };

int formato_L[] = {
                   0b00010000, //*
                   0b00110000, //*
                   0b01010000, //*
                   0b01110000, //*
                   0b10010000, //*
                   0b10110000, //*
                   0b11011110  //****
                };

int formato_M[] = {
                   0b00010001, //*   *
                   0b00110001, //*   *
                   0b01011011, //** ** 
                   0b01111011, //** **
                   0b10010101, //* * *
                   0b10110001, //*   *  
                   0b11010001  //*   *   
                };

int formato_N[] = {
                   0b00010010, //*  * 
                   0b00110010, //*  *
                   0b01010010, //*  *
                   0b01111010, //** *
                   0b10011010, //** *
                   0b10110110, //* **
                   0b11010010  //*  *
                };

int formato_O[] = {    
                   0b00011110,  //****  
                   0b00110010,  //*  * 
                   0b01010010,  //*  *
                   0b01110010,  //*  *
                   0b10010010,  //*  * 
                   0b10110010,  //*  *
                   0b11011110   //****
    };

int formato_P[] = {    
                   0b00011100,  //***    
                   0b00110010,  //*  *
                   0b01010010,  //*  *
                   0b01111100,  //***
                   0b10010000,  //*
                   0b10110000,  //*
                   0b11010000   //*
    };

int formato_Q[] = {    
                   0b00001100,  // **   
                   0b00110010,  //*  *
                   0b01010010,  //*  *
                   0b01110010,  //*  *
                   0b10010010,  //*  *
                   0b10111110,  //****
                   0b11000100   //  *
    };

int formato_R[] = {               
                   0b00011110,  //**** 
                   0b00110010,  //*  *
                   0b01010010,  //*  *
                   0b01111110,  //**** 
                   0b10011000,  //**   
                   0b10110100,  //* *  
                   0b11010010   //*  *
};

int formato_S[] = {    
                   0b00011110,  //**** 
                   0b00110000,  //*
                   0b01010000,  //*
                   0b01111110,  //****
                   0b10010010,  //   *
                   0b10110010,  //   *
                   0b11011110   //****
    };

int formato_T[] = {
                   0b00001110,  // *** 
                   0b00100100,  //  *  
                   0b01000100,  //  *  
                   0b01100100,  //  *  
                   0b10000100,  //  *  
                   0b10100100,  //  *  
                   0b11000100   //  *  
               };
int formato_U[] = {    
                   0b00010010,  //*  *    
                   0b00110010,  //*  *
                   0b01010010,  //*  *
                   0b01110010,  //*  *
                   0b10010010,  //*  *
                   0b10110010,  //*  *
                   0b11011110   //****
    };

int formato_V[] = {0b00010010, //*  *
                   0b00110010, //*  *
                   0b01010010, //*  *
                   0b01110010, //*  *
                   0b10010010, //*  *
                   0b10101100, // ** 
                   0b11000100  // *  
                  };

int formato_W[] = {    
                   0b00010001,  //*   *   
                   0b00110001,  //*   *
                   0b01010001,  //*   *
                   0b01110101,  //* * *
                   0b10011011,  //** **
                   0b10111011,  //** **
                   0b11010001   //*   *
    };

int formato_X[] = {    
                   0b00010010,  //*  *  
                   0b00110010,  //*  *
                   0b01001100,  // **
                   0b01101000,  // *
                   0b10001100,  // ** 
                   0b10110010,  //*  *
                   0b11010010   //*  *
    };

int formato_Y[] = {    
                   0b00010010,  //*  *   
                   0b00110010,  //*  *
                   0b01010010,  //*  *
                   0b01101100,  // ** 
                   0b10001000,  // * 
                   0b10101000,  // *
                   0b11001000   // *
    };

int formato_Z[] = {    
                   0b00011110,  //****    
                   0b00100010,  //   *
                   0b01000100,  //  *
                   0b01101000,  // *
                   0b10010000,  //*
                   0b10110000,  //*
                   0b11011110   //****
    };
 
 int LIMPA[] = {
  0b11000000   //*  *
};
void setup()
{

  pinMode(LATCH, OUTPUT);  // Configura o pino 2 como saída
  pinMode(CLOCK, OUTPUT);  // Configura o pino 12 como saída
  pinMode(DATA, OUTPUT);   // Configura o pino 4 como saída

 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 mySerial.begin(9600);
 SendCommand("AT+RST", "Ready");
 delay(5000);
 SendCommand("AT+CWMODE=1","OK");
 SendCommand("AT+CIFSR", "OK");
 SendCommand("AT+CIPMUX=1","OK");
 SendCommand("AT+CIPSERVER=1,80","OK");
}
 
void loop(){

 String IncomingString="";
 boolean StringReady = false;
 
 while (mySerial.available()){
   IncomingString=mySerial.readString();
   StringReady= true;

  }
 
  if (StringReady){
    Serial.println("Received String: " + IncomingString);
  int aux = IncomingString[7];
  for(int a =0; a<aux; a++){
    
    Serial.println(IncomingString[a]);


   switch(IncomingString[a]){
    	case 'V':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_V[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH

  Serial.println(formato_V[i], BIN);
	delay(200);
  }
      break;
      case 'O':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_O[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH

  Serial.println(formato_O[i], BIN);
	delay(200);
  }
      break;
   }

};


  if (IncomingString.indexOf("LED=ON") != -1) {
    digitalWrite(LED,HIGH);
        mySerial.println("AT+CIPSEND=0,23");
    mySerial.println("<h1>ZZZZZZ LED LIGADOO!</h1>");
    delay(1000);
    SendCommand("AT+CIPCLOSE=0","OK");
        for (int i = 0; i < 7; i++) {
          digitalWrite(LATCH, LOW);                       // Nível lógico baixo no pino de LATCH
          shiftOut(DATA, CLOCK, LSBFIRST, formato_A[i]);  // Função para o control e do 74HC595
          digitalWrite(LATCH, HIGH);                      // Nível lógico alto no pin o de LATCH

          Serial.println(formato_A[i], BIN);
          delay(1000);
        }
        digitalWrite(LATCH, LOW);
        shiftOut(DATA, CLOCK, LSBFIRST, LIMPA[0]);
        digitalWrite(LATCH, HIGH);
   }
    if (IncomingString.indexOf("JOSE") != -1) {
        mySerial.println("AT+CIPSEND=0,14");
    mySerial.println("<h1>JOSE</h1>");
    delay(1000);
    SendCommand("AT+CIPCLOSE=0","OK");
   }
 
  if (IncomingString.indexOf("LED=OFF") != -1) {
    digitalWrite(LED,LOW);
    mySerial.println("AT+CIPSEND=0,23");
    mySerial.println("<h1>ZZZZZZ LED DESLIGA!</h1>");
    delay(1000);
    SendCommand("AT+CIPCLOSE=0","OK");
   }
  }
 }
 
boolean SendCommand(String cmd, String ack){
  mySerial.println(cmd); // Send "AT+" command to module
  if (!echoFind(ack)) // timed out waiting for ack string
    return true; // ack blank or ack found
}
 
boolean echoFind(String keyword){
 byte current_char = 0;
 byte keyword_length = keyword.length();
 long deadline = millis() + TIMEOUT;
 while(millis() < deadline){
  if (mySerial.available()){
    char ch = mySerial.read();
    Serial.write(ch);
    if (ch == keyword[current_char])
      if (++current_char == keyword_length){
       Serial.println();
       return true;
    }
   }
  }
 return false; // Timed out
}
