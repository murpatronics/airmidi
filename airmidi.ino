#include <Wire.h>
#include <skywriter.h>

#define PIN_TRFD 12
#define PIN_REST 13

void setup() {
  Serial.begin(9600);
  while(!Serial){};
  Serial.println("Hello World!");

  Skywriter.begin(PIN_TRFD, PIN_REST);
  Skywriter.onXYZ(handle_xyz);
}

void loop() {
  Skywriter.poll();
}

void handle_xyz(unsigned int x, unsigned int y, unsigned int z){
 char buf[17];
 sprintf(buf, "%05u:%05u:%05u", x, y, z);
 Serial.println(buf);
}
