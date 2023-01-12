#define BLYNK_TEMPLATE_ID "TMPL_Cb-kCSM"
#define BLYNK_DEVICE_NAME "KRISHI HAL"
#define BLYNK_AUTH_TOKEN "TouXWWAuWcnng6ub2WqmSBat1R4bY2WC"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include<WiFiClient.h>
//#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp32.h>


#include <DHT.h>
//#include <DHT_U.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "saloni";  // type your wifi name
char pass[] = "13572468";  // type your wifi password

//#include<DHTesp.h>

DHT dht(26,DHT11);

int mini=0;
int maxi=4095;
int percentage;

int sensor_value;
const int sensor_pin = 2;
int flamesensor = 35;
int flame = LOW ;
int sensorPin = 33;
volatile long pulse;
unsigned long lastTime;
float volume;

//float THERMISTORPIN = 36;
//int buzzerpin = 10;

void setup() {
  // put your setup code here, to run once:
    
    //pinMode(buzzerpin,OUTPUT);
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(flamesensor, INPUT);
pinMode(sensorPin, INPUT);
attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
    dht.begin();
    delay(2000);

    

}

void loop() {
  // put your main code here, to run repeatedly:

  //float reading;

  //reading = analogRead(THERMISTORPIN);

  float temp=dht.readTemperature();
  float humidity=dht.readHumidity();
 volume = 2.663 * pulse;
  if (millis() - lastTime > 1000) {
    pulse = 0;
    lastTime = millis();
  }
  
  if(volume>1)
  {
    Serial.println("water found");
    Serial.print(volume);
  Serial.println(" mL/s");
  Blynk.virtualWrite(V4, 1);
  }
  else{
    Serial.println("water not found");
    Serial.print(volume);
  Serial.println(" mL/s");
  Blynk.virtualWrite(V4, 0);
  }
  

     Blynk.run();
     
    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, humidity);
    flame = digitalRead(flamesensor);


  if (flame == LOW) {
   Serial.println( " fire found");
   Blynk.virtualWrite(V5,1);
   Blynk.logEvent("fire_event");

  }
  else{

    Serial.println( " fire not found");
    Blynk.virtualWrite(V5,0);
  }
sensor_value = analogRead(sensor_pin);
  percentage = (sensor_value - mini) / (maxi - mini)*100;
  Serial.print("Moisture = ");
  Serial.print(percentage);  /* Print Temperature on the serial window */
  Serial.println("%");
  Blynk.virtualWrite(V2, percentage);
  delay(1000);
  

  Serial.print("Temp:");
  Serial.print(temp);
  Serial.print(" C ");
  Serial.print("Humidity ");
  Serial.print(humidity);
  Serial.println(" % ");
  delay(2000);

  Blynk.virtualWrite(V6,8);
  Blynk.virtualWrite(V7,25);
  Blynk.virtualWrite(V8,53);
    
  delay(2000);

//Serial.print("Analog reading");
//Serial.println(reading);
// if (reading<100)
// {
//   digitalWrite(buzzerpin,HIGH);

// }

//   else
// {
//   digitalWrite(buzzerpin,LOW);
// }

// delay(1000);


}
void increase() {
  pulse++;
}
  