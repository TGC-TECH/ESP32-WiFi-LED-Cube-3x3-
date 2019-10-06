
#include <WiFi.h> 
// Variables to store network name and password
const char* ssid = "Cowles-WiFi"; // Enter your network name
const char* password = "2033240205"; //Enter your network password

// Set the server port nunber to deafualt 80
WiFiServer server(80);

// this variable header stores the HTTP requests data
String header;

int ani_one = 1;
int ani_two = 1;
int ani_1 = 1;
int ani_2 = 0;

unsigned long Time;

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
Serial.begin(115200); //define serial commuination with baud rate of 115200

Serial.print("Making connection to "); // it will display message on serial monitor
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
// These lines prints the IP address value on serial monitor 
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();
  
  // grid pins: 

  //grid pins back
  pinMode(13, OUTPUT); //left
   pinMode(12, OUTPUT); //middle
    pinMode(14, OUTPUT); //right

    //grid pins middle
    pinMode(27, OUTPUT); //left
        pinMode(26, OUTPUT); //middle
    pinMode(25, OUTPUT); //right 

    //grid pins front
    pinMode(33, OUTPUT); //left
        pinMode(32, OUTPUT); //middle
    pinMode(23, OUTPUT); //right



    //tranistor pins
     pinMode(15, OUTPUT);  //middle layer
      pinMode(2, OUTPUT);  //top layer
            pinMode(4, OUTPUT); //bottom layer

}

// the loop function runs over and over again forever
void loop() {

  WiFiClient client = server.available();     //Checking if any client request is available or not
  if (client)
{
    boolean currentLineIsBlank = true;
    String buffer = "";  
    while (client.connected())
{
      if (client.available())                    // if there is some client data available
{
        char c = client.read(); 
        buffer+=c;                              // read a byte
        if (c == '\n' && currentLineIsBlank)    // check for newline character, 
{
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
 
          client.println();    
          client.print("<HTML><title>ESP32</title>");
          client.print("<body><h1>ESP32 LED CONTROL </h1>");
           client.print("<a href=\"/?off\"\"><button>DISABLE ALL</button></a>");
           
          client.print("<p>Animation One</p>");
          client.print("<a href=\"/?oneon\"\"><button>ON</button></a>");
          client.print("<a href=\"/?oneoff\"\"><button>OFF</button></a>");

           client.print("<p>Animation Two</p>");
          client.print("<a href=\"/?twoon\"\"><button>ON</button></a>");
          client.print("<a href=\"/?twooff\"\"><button>OFF</button></a>");

          
          client.print("</body></HTML>");
          break;        // break out of the while loop:
}
        if (c == '\n') { 
          currentLineIsBlank = true;
          buffer="";       
}
else
          if (c == '\r') {     
          if(buffer.indexOf("GET /?oneon")>=0){
           ani_one = 1;
           ani_1 = 1;
               Time = millis() - 200; }

          if(buffer.indexOf("GET /?oneoff")>=0){
           ani_one = 0;  
           ani_1 = 0; }

 if(buffer.indexOf("GET /?twoon")>=0){
           ani_two = 1;
           ani_2 = 1;
             Time = millis() - 200; }
             
          if(buffer.indexOf("GET /?twooff")>=0){
           ani_two = 0; 
           ani_2 = 0; }
           
            if(buffer.indexOf("GET /?off")>=0){
              ani_2 = 0;
              ani_1 = 0;
              digitalWrite(13, LOW);  
   digitalWrite(12, LOW);
    digitalWrite(14, LOW);
     digitalWrite(15, LOW);
      digitalWrite(4, LOW);
        digitalWrite(2, LOW);
         digitalWrite(27, LOW);
    digitalWrite(26, LOW);
     digitalWrite(25, LOW);
      digitalWrite(33, LOW);
        digitalWrite(32, LOW);
      
            }
          
}
else {
          currentLineIsBlank = false;
}
}
}
    client.stop();
}





if (ani_1 == 1){
  if(millis() < Time+500){
    //sets up layer
digitalWrite(4, HIGH);
digitalWrite(15, LOW);
digitalWrite(2, LOW);

//sets up back row
  digitalWrite(13, HIGH);  
   digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    

    
    }

if(millis() >= Time+1000 && millis() < Time+1500){
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
   }

  if(millis() >= Time+2000 && millis() < Time+2500){
    digitalWrite(14, HIGH);
    digitalWrite(12,LOW); }

    if(millis() >= Time+3000 && millis() < Time+3500){
    digitalWrite(27, HIGH);
    digitalWrite(14,LOW); }

 if(millis() >= Time+4000 && millis() < Time+4500){
    digitalWrite(26, HIGH);
    digitalWrite(27,LOW); }

     if(millis() >= Time+5000 && millis() < Time+5500){
    digitalWrite(25, HIGH);
    digitalWrite(26,LOW); }

     if(millis() >= Time+6000 && millis() < Time+6500){
    digitalWrite(33, HIGH);
    digitalWrite(25,LOW); }

     if(millis() >= Time+7000 && millis() < Time+7500){
    digitalWrite(32, HIGH);
    digitalWrite(33,LOW); }

     if(millis() >= Time+8000 && millis() < Time+8500){
    digitalWrite(23, HIGH);
    digitalWrite(32,LOW); }

 if(millis() >= Time+9000 && millis() < Time+9500){
    //sets up layer
digitalWrite(4, LOW);
digitalWrite(15, HIGH);
digitalWrite(2, LOW);

//sets up back row
  digitalWrite(13, HIGH);  
   digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    digitalWrite(23, LOW);
    
    
    }

    if(millis() >= Time+10000 && millis() < Time+10500){
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
   }

  if(millis() >= Time+11000 && millis() < Time+11500){
    digitalWrite(14, HIGH);
    digitalWrite(12,LOW); }

    if(millis() >= Time+12000 && millis() < Time+12500){
    digitalWrite(27, HIGH);
    digitalWrite(14,LOW); }

 if(millis() >= Time+13000 && millis() < Time+13500){
    digitalWrite(26, HIGH);
    digitalWrite(27,LOW); }

     if(millis() >= Time+14000 && millis() < Time+14500){
    digitalWrite(25, HIGH);
    digitalWrite(26,LOW); }

     if(millis() >= Time+15000 && millis() < Time+15500){
    digitalWrite(33, HIGH);
    digitalWrite(25,LOW); }

     if(millis() >= Time+16000 && millis() < Time+16500){
    digitalWrite(32, HIGH);
    digitalWrite(33,LOW); }

     if(millis() >= Time+17000 && millis() < Time+17500){
    digitalWrite(23, HIGH);
    digitalWrite(32,LOW); }


    if(millis() >= Time+18000 && millis() < Time+18500){
    //sets up layer
digitalWrite(4, LOW);
digitalWrite(15, LOW);
digitalWrite(2, HIGH);

//sets up back row
  digitalWrite(13, HIGH);  
   digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    digitalWrite(23, LOW);
    
    
    }

    if(millis() >= Time+19000 && millis() < Time+19500){
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
   }

  if(millis() >= Time+20000 && millis() < Time+20500){
    digitalWrite(14, HIGH);
    digitalWrite(12,LOW); }

    if(millis() >= Time+21000 && millis() < Time+21500){
    digitalWrite(27, HIGH);
    digitalWrite(14,LOW); }

 if(millis() >= Time+22000 && millis() < Time+22500){
    digitalWrite(26, HIGH);
    digitalWrite(27,LOW); }

     if(millis() >= Time+23000 && millis() < Time+23500){
    digitalWrite(25, HIGH);
    digitalWrite(26,LOW); }

     if(millis() >= Time+24000 && millis() < Time+24500){
    digitalWrite(33, HIGH);
    digitalWrite(25,LOW); }

     if(millis() >= Time+25000 && millis() < Time+25500){
    digitalWrite(32, HIGH);
    digitalWrite(33,LOW); }

     if(millis() >= Time+26000 && millis() < Time+26500){
    digitalWrite(23, HIGH);
    digitalWrite(32,LOW); }

    
    
    if(millis() >= Time+27000){
        Time = millis()-200;
        digitalWrite(23, LOW);
      if(ani_two == 1){

        ani_1 = 0; 
        ani_2 = 1;
      }
        
        }
}


if(ani_2 == 1){
   if(millis() < Time+500){
    //sets up layer
digitalWrite(4, HIGH);
digitalWrite(15, LOW);
digitalWrite(2, LOW);

//sets up back row
  digitalWrite(13, HIGH);  
   digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    
    
    }

if(millis() >= Time+1000 && millis() < Time+1500){
   digitalWrite(12, HIGH);
   //digitalWrite(13, LOW);
   }

  if(millis() >= Time+2000 && millis() < Time+2500){
    digitalWrite(14, HIGH);
    //digitalWrite(12,LOW);
    }

    if(millis() >= Time+3000 && millis() < Time+3500){
    digitalWrite(27, HIGH);
    //digitalWrite(14,LOW);
    }

 if(millis() >= Time+4000 && millis() < Time+4500){
    digitalWrite(26, HIGH);
    //digitalWrite(27,LOW); 
    }

     if(millis() >= Time+5000 && millis() < Time+5500){
    digitalWrite(25, HIGH);
    //digitalWrite(26,LOW); 
    }

     if(millis() >= Time+6000 && millis() < Time+6500){
    digitalWrite(33, HIGH);
    //digitalWrite(25,LOW);
    }

     if(millis() >= Time+7000 && millis() < Time+7500){
    digitalWrite(32, HIGH);
    //digitalWrite(33,LOW);
    }

     if(millis() >= Time+8000 && millis() < Time+8500){
    digitalWrite(23, HIGH);
    //digitalWrite(32,LOW); 
     }

 if(millis() >= Time+9000 && millis() < Time+9500){
    //sets up layer
//digitalWrite(4, LOW);
digitalWrite(15, HIGH);
digitalWrite(2, LOW);

//sets up back row
  digitalWrite(13, HIGH);  
   digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    digitalWrite(23, LOW);
    digitalWrite(27, LOW);
        digitalWrite(26, LOW);
    digitalWrite(25, LOW);
digitalWrite(33,LOW);
digitalWrite(32,LOW);
digitalWrite(35,LOW);
    
    
    }

    if(millis() >= Time+10000 && millis() < Time+10500){
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
   }

  if(millis() >= Time+11000 && millis() < Time+11500){
    digitalWrite(14, HIGH);
    digitalWrite(12,LOW); }

    if(millis() >= Time+12000 && millis() < Time+12500){
    digitalWrite(27, HIGH);
    digitalWrite(14,LOW); }

 if(millis() >= Time+13000 && millis() < Time+13500){
    digitalWrite(26, HIGH);
    digitalWrite(27,LOW); }

     if(millis() >= Time+14000 && millis() < Time+14500){
    digitalWrite(25, HIGH);
    digitalWrite(26,LOW); }

     if(millis() >= Time+15000 && millis() < Time+15500){
    digitalWrite(33, HIGH);
    digitalWrite(25,LOW); }

     if(millis() >= Time+16000 && millis() < Time+16500){
    digitalWrite(32, HIGH);
    digitalWrite(33,LOW); }

     if(millis() >= Time+17000 && millis() < Time+17500){
    digitalWrite(23, HIGH);
    digitalWrite(32,LOW); }


    if(millis() >= Time+18000 && millis() < Time+18500){
    //sets up layer
//digitalWrite(4, LOW);
//digitalWrite(15, LOW);
digitalWrite(2, HIGH);

//sets up back row
  digitalWrite(13, HIGH);  
   digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    digitalWrite(23, LOW);
       digitalWrite(12, LOW);
    digitalWrite(14,LOW);
    digitalWrite(23, LOW);
    digitalWrite(27, LOW);
        digitalWrite(26, LOW);
    digitalWrite(25, LOW);
digitalWrite(33,LOW);
digitalWrite(32,LOW);
digitalWrite(35,LOW);
    
    }

    if(millis() >= Time+19000 && millis() < Time+19500){
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
   }

  if(millis() >= Time+20000 && millis() < Time+20500){
    digitalWrite(14, HIGH);
    digitalWrite(12,LOW); }

    if(millis() >= Time+21000 && millis() < Time+21500){
    digitalWrite(27, HIGH);
    digitalWrite(14,LOW); }

 if(millis() >= Time+22000 && millis() < Time+22500){
    digitalWrite(26, HIGH);
    digitalWrite(27,LOW); }

     if(millis() >= Time+23000 && millis() < Time+23500){
    digitalWrite(25, HIGH);
    digitalWrite(26,LOW); }

     if(millis() >= Time+24000 && millis() < Time+24500){
    digitalWrite(33, HIGH);
    digitalWrite(25,LOW); }

     if(millis() >= Time+25000 && millis() < Time+25500){
    digitalWrite(32, HIGH);
    digitalWrite(33,LOW); }

     if(millis() >= Time+26000 && millis() < Time+26500){
    digitalWrite(23, HIGH);
    digitalWrite(32,LOW); }

    
    
    if(millis() >= Time+27000){
        Time = millis()-200;
        digitalWrite(23, LOW);
        
  
  if(ani_one == 1){
    ani_1 = 1;
    ani_2 = 0;
  }

if(ani_one == 0){
  ani_2 = 1;
}
  
}}

 
 }
