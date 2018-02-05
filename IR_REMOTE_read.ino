//2017.06.22

#include <IRremote.h>
#include <LiquidCrystal.h>

/* HOW TO WIRE UP LCD SCREEN LEFT TO RIGHT PIN WITH PINS ON TOP SIDE
 *  
 *  GND - VCC - POT MIDDLE - 12 - GND - 11 - NONE - NONE - NONE - NONE - 5 - 4 - 9 - 2 - VCC - GND
 *  
 *  POT MUST HAVE 5V AND GND ON IT AND CAN ROTATE THE KNOB TO CHANGE LCD CONTRAST
 */
 
LiquidCrystal lcd(12, 11, 5, 4, 9, 2); //9 instead of 3 (NEED FOR TRANSMITTER)

int receiverpin = 10;

IRrecv irrecv(receiverpin);
decode_results results;


void setup() {
  lcd.begin(16, 2);
  pinMode(receiverpin, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    lcd.clear();
    lcd.print(results.value, HEX);
    delay(150);
  }
}
