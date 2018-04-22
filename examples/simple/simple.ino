#include <Neosegment.h>

// Which pin on the Arduino is connected to the NeoSegments?
#define PIN            6

// How many digits are attached to the Arduino?
#define NUMDIGITS      4

Neosegment display = Neosegment(NUMDIGITS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
	display.begin(); // This initializes the display
}

void loop() {

	display.drawNumber(1234, display.Color(0, 150, 0)); // draw the number in the specified color

	display.show(); // This sends the updated digits to the segments

	delay(delayval); // Delay for a period of time (in milliseconds)

}
