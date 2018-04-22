
#include "Neosegment.h"

Neosegment::Neosegment(uint16_t s, uint8_t p, neoPixelType t) : Adafruit_NeoPixel(s*7, p, t) {
	segment_count = s;
	align_right = false;
}


void Neosegment::drawNumber(uint32_t n, uint8_t r, uint8_t g, uint8_t b) {
	drawNumber(n, Adafruit_NeoPixel::Color(r, g, b));
}

void Neosegment::drawNumber(uint32_t n, uint16_t o, uint8_t r, uint8_t g, uint8_t b) {
	drawNumber(n, o, Adafruit_NeoPixel::Color(r, g, b));
}
void Neosegment::drawNumber(uint32_t n, uint32_t c) {
	drawNumber(n, 0, c);
}
void Neosegment::drawNumber(uint32_t n, uint16_t o, uint32_t c) {
	String numStr = String(n, DEC);
	for (uint16_t i = 0; i < numStr.length(); i++) {
		uint8_t digit = numStr.charAt(i) - '0';
		drawDigit(digitMap[digit], o+(i*7), c);
	}
}

void Neosegment::drawDigit(byte bits, uint16_t o, uint32_t c) {
	for (uint8_t i = 7; i > 0; i--) {
		if (bits & (1 << (i-1))) {
			setPixelColor(o+7-i, c);
		}
	}
}

void Neosegment::alignRight(bool alignright) {
	align_right = alignright;
}
