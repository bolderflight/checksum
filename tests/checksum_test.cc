/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "checksum/checksum.h"
#include "gtest/gtest.h"

/* Test the null pointer */
TEST(Fletcher16, NullPtr) {
  checksum::Fletcher16 chk;
  EXPECT_EQ(0, chk.Compute(nullptr, 10.0));
  EXPECT_EQ(0, chk.Update(nullptr, 10.0));
}
/* Test zero length */
TEST(Fletcher16, ZeroLength) {
  checksum::Fletcher16 chk;
  uint8_t test[0];
  EXPECT_EQ(0, chk.Compute(test, sizeof(test)));
  EXPECT_EQ(0, chk.Update(test, sizeof(test)));
}
/* Test known array */
TEST(Fletcher16, KnownArray) {
  checksum::Fletcher16 chk;
  uint8_t test[] = {'a','b','c','d','e'};
  EXPECT_EQ(51440, chk.Compute(test, sizeof(test)));
  chk.Reset();
  EXPECT_EQ(51440, chk.Update(test, sizeof(test)));
}
/* Test Compute method */
TEST(Fletcher16, Compute) {
  checksum::Fletcher16 chk;
  uint8_t test[] = {'a','b','c','d','e'};
  uint16_t result;
  for (std::size_t i = 0; i < sizeof(test); i++) {
    result = chk.Update(&test[i], 1);
  }
  EXPECT_EQ(51440, result);
  EXPECT_EQ(51440, chk.Compute(test, sizeof(test)));
}
