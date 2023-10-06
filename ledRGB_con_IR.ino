#include <IRremote.hpp>
int IRpin=3;
int Redpin=9;
int Greenpin=5;
int Bluepin=6;
float dFact=1;

int RBrillo=255;
int ABrillo=255;
int GBrillo=255;

void setup(){
Serial.begin(9600);
IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK);
pinMode(Redpin, OUTPUT);
pinMode(Greenpin, OUTPUT);
pinMode(Bluepin, OUTPUT);
}

void loop(){
if(IrReceiver.decode()){
String boton = String(IrReceiver.decodedIRData.decodedRawData, HEX);

Serial.println(boton); //Imprime el valor del boton en datos 32 bits

IrReceiver.resume(); 

if (boton == "f30cbf00"){               //detecta el Boton 0
 RBrillo=0;
 GBrillo=0;
 ABrillo=0;
}

if (boton == "ef10bf00"){              //detecta el Boton 1    
 RBrillo=0;
 GBrillo=255;
 ABrillo=0;
}

if (boton == "ee11bf00"){             //detecta el Boton 2
 RBrillo=0;
 GBrillo=0;
 ABrillo=255;
}

if (boton == "ed12bf00"){             //detecta el Boton 3
 RBrillo=255;
 GBrillo=0;
 ABrillo=0;
  } 
 
  if (boton == "fe01bf00"){           //detecta Boton para subir
  dFact=dFact * 1.5;
    if (dFact>1){
      dFact=1;
 
    }
 }  
  if (boton == "f609bf00"){          //detecta Boton para bajar
     dFact=dFact * .65;
    if (dFact<0){
      dFact=0;
     }
  
}
 analogWrite(Redpin, RBrillo*dFact);
 analogWrite(Greenpin, GBrillo*dFact); 
 analogWrite(Bluepin, ABrillo*dFact); 
 }
}  
  