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
  //     ABCDEFG  Segments      7-segment map:
  B01110111, // 0   "0"          BBB
  B00010001, // 1   "1"         A   C
  B00111110, // 2   "2"         A   C
  B00111011, // 3   "3"          DDD
  B01011001, // 4   "4"         E   G
  B01101011, // 5   "5"         E   G
  B01101111, // 6   "6"          FFF
  B00110001, // 7   "7"
  B01111111, // 8   "8"
  B01111011  // 9   "9"
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
