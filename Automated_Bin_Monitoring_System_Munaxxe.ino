// Automated Bin Monitoring System - Munaxxe
#include <Wire.h>
#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <WiFi.h>
#include "ThingSpeak.h"
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <ESP32Servo.h>

// Ultrasonic Pin Initialisation
const int trigPin = 5;
const int echoPin = 18;

static const int servoPin = 23;
static const int proximity = 22;
int readProximity;

Servo servo;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
 
// Wifi Network Credentials
const char* ssid = "";       // Replace with your Network SSID (name) 
const char* password = "";   // Replace with your Network password

WiFiClient  client;

unsigned long myChannelNumber = ; // Replace with your channel number
const char * myWriteAPIKey = "";         // Replace with your API key

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

// Bin Level
float binLevel = 0.0;

// Bin Status
bool binStatus = false;

void setup() {
  // Initialising serial communication
  Serial.begin(9600);             
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialising ThingSpeak
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(proximity, INPUT);
}

void loop() {

  if ((millis() - lastTime) > timerDelay) {
  
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, password); 
      delay(1000);     
    } 
    Serial.println("\nConnected.");
  }

// Reading the Value of the IR sensor to Open/Close the door
readProximity = digitalRead(proximity);

// Bin Open & Close Algo
  if(readProximity == LOW){
    Serial.println("Lid Open");
    servo.write(150);
    delay(500);
    }
    
  if(readProximity == HIGH){
    Serial.println("Lid Close");
    servo.write(0);
    delay(500);
    }

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  if(distanceCm <= 5){
  binStatus = true;
  delay(50);
  }

  if(distanceCm > 5){
  binStatus= false;
  delay(50);
  }
  
  delay(1000);
  
    binLevel = map(distanceCm, 0, 13, 100, 0);
    Serial.print("Bin Level: ");
    Serial.println(binLevel);
 if(binLevel < 0){
  binLevel = 0;
  }
    // Setting the fields with the values
    ThingSpeak.setField(1, binStatus);
    ThingSpeak.setField(2, binLevel);


    // Write to ThingSpeak
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
