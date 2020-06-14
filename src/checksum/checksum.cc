/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "checksum/checksum.h"

namespace checksum {

uint16_t Fletcher16(uint8_t *data, std::size_t len) {
  if ((len == 0) || (!data)) {
    return 0;
  }
  uint16_t sum0, sum1;
  for (std::size_t i = 0, sum0 = 0, sum1 = 0; i < len; i++) {
    sum0 = (sum0 + data[i]) % 0xFF;
    sum1 = (sum1 + sum0) % 0xFF;
  }
  return sum1 << 8 | sum0;
}

}  // namespace checksum
