#include <SPI.h>
#include <RF24.h>
#include <ezButton.h>

#define CE_PIN    9   // انتخاب یک پین مناسب برای CE
#define CSN_PIN   10  // انتخاب یک پین مناسب برای CSN
#define SCK_PIN   12  // پین SCK برای ESP32-S3
#define MOSI_PIN  11  // پین MOSI
#define MISO_PIN  13  // پین MISO

#define SWITCH_BT_PIN 5  // پین بالا (بلوتوث + nRF24)
#define SWITCH_WIFI_PIN 6 // پین پایین (تداخل روی کانال‌های وای‌فای)

RF24 radio(CE_PIN, CSN_PIN);

byte i = 45;  // کانال شروع برای بلوتوث
unsigned int flag = 0;
ezButton toggleSwitch(4); // دکمه به پین 4 متصل می‌شود

void setup() {
  Serial.begin(115200);
  pinMode(SWITCH_BT_PIN, INPUT_PULLUP);
  pinMode(SWITCH_WIFI_PIN, INPUT_PULLUP);

  // تنظیم دستی پین‌های SPI در ESP32-S3
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);
  
  if (digitalRead(SWITCH_BT_PIN) == LOW) { // حالت بالا -> فعال‌سازی بلوتوث و nRF24L01
    Serial.println("Bluetooth Mode");
    startNRF24(37, 50);
  } 
  else if (digitalRead(SWITCH_WIFI_PIN) == LOW) { // حالت پایین -> تداخل روی کانال‌های وای‌فای
    Serial.println("WiFi Interference Mode");
    startNRF24(1, 14);
  } 
  else {
    Serial.println("Switch in middle position. No action.");
  }
}

void startNRF24(byte startChannel, byte endChannel) {
  if (radio.begin()) {
    delay(200);
    Serial.println(F("NRF24 Started!"));
    
    radio.setAutoAck(false);
    radio.stopListening();
    radio.setRetries(0, 0);
    radio.setPayloadSize(5);
    radio.setAddressWidth(3);
    radio.setPALevel(RF24_PA_MAX);
    radio.setDataRate(RF24_2MBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);
    
    radio.printDetails();
    radio.startConstCarrier(RF24_PA_MAX, startChannel);
    i = startChannel;
  } else {
    Serial.println(F("NRF24 failed to start!"));
    while (1) {}
  }
}

void two() {
  if (flag == 0) {
    i += 2;
  } else {
    i -= 2;
  }

  if ((i > 79) && (flag == 0)) {
    flag = 1;
  } else if ((i < 2) && (flag == 1)) {
    flag = 0;
  }

  radio.setChannel(i);
}

void one() {
  for (int i = 0; i < 79; i++) {
    radio.setChannel(i);
  }
}

void loop() {
  toggleSwitch.loop();
  if (digitalRead(SWITCH_BT_PIN) == LOW || digitalRead(SWITCH_WIFI_PIN) == LOW) {
    int state = toggleSwitch.getState();
    if (state == HIGH) {
      two();
    } else {
      one();
    }
  }
}
