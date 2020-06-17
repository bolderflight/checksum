/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include <iostream>
#include "checksum/checksum.h"

int main() {
  /* Checksum object */
  checksum::Fletcher16 chk;
  /* Single pass checksum */
  uint8_t test[] = {'a','b','c','d','e'};
  uint16_t result = chk.Compute(test, sizeof(test));
  std::cout << result << std::endl;  // 51440
  /* Multi-pass checksum */
  chk.Reset();
  for (std::size_t i = 0; i < sizeof(test); i++) {
    result = chk.Update(&test[i], 1);
  }
  std::cout << result << std::endl;  // 51440
  chk.Reset();
  uint8_t test2[] = {'a','b','c','d','e','f','g','h'};
  for (std::size_t i = 0; i < sizeof(test2); i++) {
    result = chk.Update(&test2[i], 1);
  }
  std::cout << result << std::endl;  // 1575
}
