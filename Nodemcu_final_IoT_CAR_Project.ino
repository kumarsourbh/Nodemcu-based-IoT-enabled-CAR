/* Iot Enabled CAR Project by S.Kumar
 *  Youtube - Learn Robotics with Sourbh Kumar
 *  MIT App Inventor based Mobile Application to control the BOT
 *  Follow for more tutorials in Robotics & AI
 */
#define ENA 14    //Enable/Speed of Motor Right Side (D5) in NodeMCU
#define ENB 12    //Enable/Speed of Motor Left side (D6) in NodeMCU
#define IN_1 15   //D8
#define IN_2 13   //D7
#define IN_3 2    //D4
#define IN_4 0    //D3

// These above will be our Pins configuration for Motors through the L298N motor Driver>> Now the Setup part where 
//we have to declare the purpose of the pins, but before that we have to include some of the essential header files/Library for the same

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
String command;           //String to store app command state.

const char* ssid = "XRobotics IoT CAR";
ESP8266WebServer server(80);
 
void setup() {
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);  
pinMode(IN_1, OUTPUT);
pinMode(IN_2, OUTPUT);
pinMode(IN_3, OUTPUT);
pinMode(IN_4, OUTPUT);
  
  Serial.begin(115200);
  
// Connecting WiFi
 
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);
 
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
// Starting WEB-server
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}
 
void goAhead(){
 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(ENA, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(ENB, HIGH);
  }
 
void goBack(){
 
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(ENA, HIGH);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      digitalWrite(ENB, HIGH);
  }
 
void goRight(){
 
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(ENA, HIGH);
 
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(ENB, HIGH);
  }
 
void goLeft(){
 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(ENA, HIGH);
 
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      digitalWrite(ENB, HIGH);
  }
 
void goAheadRight(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(ENA, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(ENB, HIGH);
   }
 
void goAheadLeft(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(ENA, HIGH);
 
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(ENB, HIGH);
  }
 
void goBackRight(){
 
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(ENA, HIGH);
 
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      digitalWrite(ENB, HIGH);
  }
 
void goBackLeft(){
 
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(ENA, HIGH);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      digitalWrite(ENB, HIGH);
  }
 
void stopRobot(){  
 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(ENA, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      digitalWrite(ENB, HIGH);
}
 
void loop() {
    server.handleClient();
    
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if (command == "S") stopRobot();
}
 
void HTTP_handleRoot(void) {
 
if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
