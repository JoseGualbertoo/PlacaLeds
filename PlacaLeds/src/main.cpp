#include <Arduino.h>
#include <SoftwareSerial.h>
//#include <string.h>
#define TIMEOUT 5000 // mS
#define LED 13
SoftwareSerial mySerial(7, 6); // RX, TX
const int button = 11;
int button_state = 0;

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
 
 int LIMPA[] = {
  0b11000000   //*  *
};
void setup()
{

  pinMode(LATCH, OUTPUT);  // Configura o pino 2 como saída
  pinMode(CLOCK, OUTPUT);  // Configura o pino 12 como saída
  pinMode(DATA, OUTPUT);   // Configura o pino 4 como saída

 pinMode(LED,OUTPUT);
 pinMode(button,INPUT); 
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
 button_state = digitalRead(button);
 
 if(button_state == HIGH){
    mySerial.println("AT+CIPSEND=0,29");
    mySerial.println("<h1>Button was pressed!</h1>");
    delay(1000);
    SendCommand("AT+CIPCLOSE=0","OK");
  }
  
 String IncomingString="";
 boolean StringReady = false;
 
 while (mySerial.available()){
   IncomingString=mySerial.readString();
   StringReady= true;
  }
 
  if (StringReady){
    Serial.println("Received String: " + IncomingString);
  
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
