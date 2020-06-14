/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "checksum/checksum.h"

namespace checksum {

uint16_t Fletcher16::Compute(uint8_t *data, std::size_t len) {
  if ((len == 0) || (!data)) {
    return 0;
  }
  for (std::size_t i = 0, sum0_ = 0, sum1_ = 0; i < len; i++) {
    sum0_ = (sum0_ + data[i]) % 0xFF;
    sum1_ = (sum1_ + sum0_) % 0xFF;
  }
  return sum1_ << 8 | sum0_;
}

void Fletcher16::Reset() {
  sum0_ = 0;
  sum1_ = 0;
}

uint16_t Fletcher16::Increment(uint8_t *data, std::size_t len) {
  if ((len == 0) || (!data)) {
    return 0;
  }
  for (std::size_t i = 0; i < len; i++) {
    sum0_ = (sum0_ + data[i]) % 0xFF;
    sum1_ = (sum1_ + sum0_) % 0xFF;
  }
  return sum1_ << 8 | sum0_;
}

}  // namespace checksum
