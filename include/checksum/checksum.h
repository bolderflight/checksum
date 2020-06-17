/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_CHECKSUM_CHECKSUM_H_
#define INCLUDE_CHECKSUM_CHECKSUM_H_

#include <cstdint>

namespace checksum {
/* Fletcher-16 checksum */
class Fletcher16 {
 public:
  uint16_t Compute(uint8_t *data, std::size_t len);
  void Reset();
  uint16_t Update(uint8_t *data, std::size_t len);

 private:
  uint16_t sum0_ = 0, sum1_ = 0;
};
}  // namespace checksum

#endif  // INCLUDE_CHECKSUM_CHECKSUM_H_
