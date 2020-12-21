#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
// Connect TXPin3 Arduino to RX GPS
// Connect RXPin4 Arduino to TX GPS
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.print(gps.location.lng(), 6);
      // Altitude in meters (double)
      Serial.print(" Altitude in meters = "); 
      Serial.print(gps.altitude.meters()); 
       // Number of satellites in use (u32)
      Serial.print(" Number of satellites in use = "); 
      Serial.print(gps.satellites.value()); 
      // Raw time in HHMMSSCC format (u32)
      Serial.print(" Raw time in HHMMSSCC = "); 
      Serial.println(gps.time.value()); 
      delay(5000);
    }
  }

}