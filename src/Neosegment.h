#ifndef NEOSEGMENT_H
#define NEOSEGMENT_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

#include <Adafruit_NeoPixel.h>


static const byte digitMap[] = {
//  ABCDEFG  Segments      7-segment map:
  B01110111, // 0   "0"          FFF
  B01000100, // 1   "1"         G   E
  B00111110, // 2   "2"         G   E
  B01101110, // 3   "3"          DDD
  B01001101, // 4   "4"         C   A
  B01101011, // 5   "5"         C   A
  B01111011, // 6   "6"          BBB
  B01000110, // 7   "7"
  B01111111, // 8   "8"
  B01101111  // 9   "9"
};


class Neosegment : public Adafruit_NeoPixel {

 public:
  Neosegment(uint16_t s=1, uint8_t p=6, neoPixelType t=NEO_GRB + NEO_KHZ800);

  void drawNumber(uint32_t n, uint8_t r, uint8_t g, uint8_t b);
  void drawNumber(uint32_t n, uint16_t o, uint8_t r, uint8_t g, uint8_t b);
  void drawNumber(uint32_t n, uint32_t c);
  void drawNumber(uint32_t n, uint16_t o, uint32_t c);

  void alignRight(bool alignright=true);

 protected:
  uint16_t
  	  segment_count;
  void drawDigit(byte bits, uint16_t o, uint32_t c);

 private:
  bool
  	  align_right;

};

#endif // NEOSEGMENT_H
