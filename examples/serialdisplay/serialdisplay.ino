#include <Arduino.h>
#include <Neosegment.h>

#define PIN            6
#define NUMDIGITS      8

Neosegment display = Neosegment(NUMDIGITS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
	display.begin();
	display.clear();
	display.show();
	Serial.begin(38400);
}

void loop() {
	 if(Serial.available() > 0) {
		 String numStr = Serial.readStringUntil('\n');
		 if (numStr == "") {
			 display.clear();
		 } else {
			 display.drawNumber(numStr.toInt(), display.Color(0, 150, 0));
		 }

		display.show();
	 }
}
