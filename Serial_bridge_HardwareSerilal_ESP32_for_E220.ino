/*
Serial bridge for E220-900T22S-JP Config read 

E220 is connected via hardware serial (port name: Serial2)

PLatform is ESP-WROOM-32D

For binary data transfer, use RS232 TEST tools
http://nonsoft.la.coocan.jp/Download/Rs232cTool/index.html


Jay Teramoto 2024.6.21 (Complete)
*/

#define M0pin   27      // GPIO27
#define M1pin   14      // GPIO14
#define Tx      17      // GPIO17
#define Rx      16      // GPIO16

void setup() {

  // E220 mode3 M0=1, M1=1
  pinMode(M0pin,OUTPUT);
  pinMode(M1pin,OUTPUT);
  digitalWrite(M0pin,HIGH);
  digitalWrite(M1pin,HIGH);
  
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println("E220 Config read/write via HardwareSerial2 on ESP32 ");

}

void loop() {

  while (Serial2.available()) {
    Serial.print(char(Serial2.read()));
  }
  while (Serial.available()) {
    Serial2.print(char(Serial.read()));
  }
}
