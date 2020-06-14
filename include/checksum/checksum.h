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
uint16_t Fletcher16(uint8_t *data, std::size_t len);
}  // namespace checksum

#endif  // INCLUDE_CHECKSUM_CHECKSUM_H_
