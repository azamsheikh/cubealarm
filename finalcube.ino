//#include <ArduinoRobot.h>

#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>


 const char* ssid = "Eliza-protocol";
const char* password = "2453QUEENSTREET";
//int clocktoarduino = 13;
int rubicksstandsensor = 14;
int relayswitch = 12;
int speaker = 4;

static String alarmStatus = "off";
String cubeplacement = "placed";



void setup() {


pinMode(16, OUTPUT);

pinMode(relayswitch, OUTPUT);               //pin 4 on esp
pinMode(rubicksstandsensor, INPUT);         //pin 5 on esp
pinMode(speaker, OUTPUT);         //6 on esp

Serial.begin(9600);
delay(5000);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(1000);
Serial.print("Connecting..");
}
}




void loop() {
 top: 

  

 
int rubicksstandstatus = digitalRead(rubicksstandsensor);

int sensorValue = analogRead(A0);




 Serial.print("alarmstatusstatus--");
 Serial.println(alarmStatus);
 Serial.print("rubicksstandstatus--");
 Serial.println(rubicksstandstatus);
 Serial.print("voltage--");
 Serial.println(sensorValue);

  if(rubicksstandstatus < 1){
    digitalWrite(16, HIGH); 
  }
 
else{digitalWrite(16, LOW);}
 
 
if(sensorValue >= 100)      //////some changes  //

{
  
 alarmStatus = "on";
  if (WiFi.status() == WL_CONNECTED) 
{ //Check WiFi connection status
 HTTPClient http;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=alarmstatusupdate&alarmstatus=on");  //Specify request destination
int httpCode = http.GET(); 

if (httpCode > 0) { //Check the returning code

http.end();}
}
}

else{}



if(alarmStatus == "on" && rubicksstandstatus == 0)            //ssomechanges //
{




for(int i =0;i<=70;i++)
{

Serial.print("alarmstatusstatus--");
 Serial.println(alarmStatus);
 Serial.print("rubicksstandstatus--");
 Serial.println(rubicksstandstatus);
 Serial.print("voltage--");
 Serial.println(sensorValue);
  
  digitalWrite(speaker, LOW);
Serial.println("forloop");
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 HTTPClient http;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=checkcubesolvestatus");  //Specify request destination
int httpCode = http.GET(); 
if (httpCode > 0) { //Check the returning code
 String payload1 = http.getString();   //Get the request response payload
 Serial.println(payload1);

if(payload1 == "solved")
{
  Serial.println("alarmoff");
 
  cubeplacement == "placed";
  digitalWrite(relayswitch, HIGH);
  delay(500);
  digitalWrite(relayswitch, LOW);

if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 HTTPClient http;;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=alarmstatusupdate&alarmstatus=off");  //Specify request destination
int httpCode = http.GET(); 

if (httpCode > 0) { //Check the returning code
http.end();}
}

delay(1000);
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 HTTPClient http;;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=cubesolvestatusupdate&cubesolvestatus=unsolved");  //Specify request destination
int httpCode = http.GET(); 

if (httpCode > 0) { //Check the returning code
http.end();}
}

alarmStatus = "off";

delay(2000);
break;
}

else{}

http.end();}


}
delay(1000);
}




Serial.print("alarmstatusstatus12345--");
 Serial.println(alarmStatus);
delay(10000);

while(alarmStatus == "on")
{
  Serial.println("whileloop");
delay(1000);
   tone(speaker, 1000, 1000) ;
   delay(200);
   tone(speaker, 0);
   delay(200);
   tone(speaker, 1000, 1000) ;
   delay(200);
   tone(speaker, 0);
   delay(200);
Serial.println("alarmon2");
/////////////////alarm trigger //////////////

if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 HTTPClient http;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=checkcubesolvestatus");  //Specify request destination
int httpCode = http.GET(); 

if (httpCode > 0) { //Check the returning code
 String payload3 = http.getString();   //Get the request response payload

Serial.println(payload3);

if(payload3 == "solved")
{
  
  Serial.println("alarmoff");
 alarmStatus = "off";
  digitalWrite(16, LOW);
  cubeplacement == "placed";
  digitalWrite(relayswitch, HIGH);
  delay(500);
  digitalWrite(relayswitch, LOW);




  if (WiFi.status() == WL_CONNECTED) 
{ //Check WiFi connection status
 HTTPClient http;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=alarmstatusupdate&alarmstatus=off");  //Specify request destination
int httpCode = http.GET(); 

if (httpCode > 0) { //Check the returning code

http.end();}
}
delay(1000);


if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 HTTPClient http;;  //Declare an object of class HTTPClient
 http.begin("http://azamitaweb.com/cubealarm.php?process=cubesolvestatusupdate&cubesolvestatus=unsolved");  //Specify request destination
int httpCode = http.GET(); 

if (httpCode > 0) { //Check the returning code
http.end();}
}



alarmStatus = "off";

delay(2000);

break;




}

else{}

http.end();
}
}



  
}                 ///////////////////////////////////////////



}


else if(alarmStatus == "on" && rubicksstandstatus == 1)

{
   /////////////////alarm trigger //////////////
   Serial.println("alarmon1");
   delay(1000);
   tone(speaker, 1000, 1000) ;
   delay(200);
   tone(speaker, 0);
   delay(200);
   tone(speaker, 1000, 1000) ;
   delay(200);
   tone(speaker, 0);
   delay(200);
}




else if(alarmStatus == "off" )

{
  
 Serial.println("alarmoff");


  
  }

  else{}


















}
