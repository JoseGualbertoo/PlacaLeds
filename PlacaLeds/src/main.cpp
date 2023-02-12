#define DATA 2 // Define DATA como 2
#define LATCH 3 // Define LATCH como 3
#define CLOCK 4 // Define CLOCK como 4
int formato_A[] = {
                   0b00001100, // **  
                   0b00110010, //*  * 
                   0b01010010, //*  *
                   0b01111110, //****
                   0b10010010, //*  *
                   0b10110010, //*  *
                   0b11010010  //*  *
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
unsigned char byte_linha;
char cont = 0;

void setup()
{
pinMode (LATCH , OUTPUT); // Configura o pino 2 como saída
pinMode (CLOCK , OUTPUT); // Configura o pino 12 como saída
pinMode (DATA, OUTPUT); // Configura o pino 4 como saída
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0){
  cont = Serial.read();
    delay(500);
    switch(cont){
    	case 'V':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_V[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH
	
  Serial.println(formato_V[i], BIN);
	delay(200);
  }
      break;
      case 'I':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_I[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH
	
  Serial.println(formato_I[i], BIN);
	delay(200);
  }
      break;
      case 'K':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_K[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH
	
  Serial.println(formato_K[i], BIN);
	delay(200);
  }
      break;
      case 'T':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_T[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH
	
  Serial.println(formato_T[i], BIN);
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
      case 'R':
      for(int i = 0; i<7; i++){
    digitalWrite(LATCH,LOW); // Nível lógico baixo no pino de LATCH
    shiftOut(DATA,CLOCK,LSBFIRST,formato_R[i]); // Função para o control e do 74HC595
    digitalWrite(LATCH,HIGH); // Nível lógico alto no pin o de LATCH
	
  Serial.println(formato_R[i], BIN);
	delay(200);
  }
      break;
    }
  }
}