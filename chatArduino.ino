//      ////      //      ////       ////      //            ////      //      //      //      //////      //////
//      //  //    //    ////       //          //          //   //     //      ////  ////      //          //  //
//      //  //    //      ////     //          //          ///////     //      //  //  //      ////        ////
//      ////      //    ////         ////      //////      //   //     //      //      //      //////      //  //
//

/*
*********************************************************************************************************************
  This is Mateus Fernandes' attempt to create a code for a chatting system;
  It is a open-source code, anyone can use it at will only under the circunstances to keep this disclaimer at the top
*********************************************************************************************************************
*/
#include <SoftwareSerial.h>

#define rxPin 10                  //connects to the txPin of the HC05
#define txPin 9                   //connects to the rxPin of the HC05
SoftwareSerial HC(rxPin,txPin);

//---------------------------------------------------------------------------------------------------------------------

String person1;
String person2;

void setup() {
  HC.begin(9600);
  Serial.begin(9600);
  HC.println("Initializing...");
  Serial.println("Initializing...");
  if(HC.available()>0){
     HC.println("What do you want to be called?");
     person2 = HC.readString();
  }
  if(Serial.available()>0){
     Serial.println("What do you want to be called?");
     person1 = Serial.readString();
  }
}

void loop() {
  if(HC.available()>0){
    String texto1 = HC.readString();
    HC.println(person2+"> "+texto1);
    Serial.println(person2+"> "+texto1);
  }
  if(Serial.available() > 0){
    String texto2 = Serial.readString();
    Serial.println(person1+"> "+texto2);
    HC.println(person1+"> "+texto2);
  }
}
