/*
Serial bridge for E220-900T22S-JP Config read/write 

E220 is connected via HardwareSerial2 (port name: Serial2)

PLatform : ESP-WROOM-32D

For binary data transfer, use RS232 TEST tools
http://nonsoft.la.coocan.jp/Download/Rs232cTool/index.html

設定確認
送-> <c1><00><08>
->受 <c0><00><08><00><00><70><01><00><C5><00><00>

※9バイトを読み込めばバージョン番号取得

設定コマンド
送-> <c0><00><08><<00><00><70><01><00><C5><00><00>
->受 <c1><00><08><00><00><70><01><00><C5><00><00>

<現在の設定>
接続 COM10
送-> <c1><00><09>
->受 <c1><00><09><00><00><70><01><00><c5><00><00><10>

Rev 0.1 2024.06.22  Initial
Rev 0.2 2024.06.25  Change M0/M1 pins
Rev 0.3 2024.06.26  Cleanup codes, add config commands

Jay Teramoto (Complete)
*/

#define M0pin   26      // New assign
#define M1pin   27      // New assign
#define AUXpin  14      // New assign (not use)
#define Tx      17      // GPIO17 U2TDX (not use)
#define Rx      16      // GPIO16 U2RDX (not use)

void setup() {

  // E220 mode3 M0=1, M1=1
  pinMode(M0pin,OUTPUT);
  pinMode(M1pin,OUTPUT);
  digitalWrite(M0pin,HIGH);
  digitalWrite(M1pin,HIGH);
  
  Serial.begin(9600);
  Serial2.begin(9600);
  delay(1000);
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
