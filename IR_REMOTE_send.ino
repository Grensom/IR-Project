
#include <IRremote.h>

IRsend irsend;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(10000);
  //Power//
  irsend.sendNEC(..., 32); //Power Code
  Serial.println("Power");
  delay(10000);
  //Volume Up//
  for (int i = 0; i < 10; i++) {
    irsend.sendNEC(..., 32); //Volume Up Code
    Serial.println("Volume Up");
    delay(250);
  }
  delay(5000);
  //Volume Down//
  for (int i = 0; i < 10; i++) {
    irsend.sendNEC(..., 32); //Volume Down Code
    Serial.println("Volume Down");
    delay(250);
  }
  delay(5000);
  //Netflix//
  irsend.sendNEC(..., 32); //Netflix Code
  Serial.println("Netflix");
  delay(10000);
}


