/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "checksum.h"
#include "gtest/gtest.h"

/* Test the null pointer */
TEST(Fletcher16, NullPtr) {
  bfs::Fletcher16 chk;
  EXPECT_EQ(0, chk.Compute(nullptr, 10.0));
  EXPECT_EQ(0, chk.Update(nullptr, 10.0));
}
/* Test zero length */
TEST(Fletcher16, ZeroLength) {
  bfs::Fletcher16 chk;
  uint8_t test[0];
  EXPECT_EQ(0, chk.Compute(test, sizeof(test)));
  EXPECT_EQ(0, chk.Update(test, sizeof(test)));
}
/* Test known array */
TEST(Fletcher16, KnownArray) {
  bfs::Fletcher16 chk;
  uint8_t test[] = {'a','b','c','d','e'};
  EXPECT_EQ(51440, chk.Compute(test, sizeof(test)));
  chk.Reset();
  EXPECT_EQ(51440, chk.Update(test, sizeof(test)));
}
/* Test std::array */
TEST(Fletcher16, stdArray) {
  bfs::Fletcher16 chk;
  std::array<uint8_t, 5> test = {'a','b','c','d','e'};
  EXPECT_EQ(51440, chk.Compute(test.data(), test.size()));
  chk.Reset();
  EXPECT_EQ(51440, chk.Update(test.data(), test.size()));
}
/* Test Compute method */
TEST(Fletcher16, Compute) {
  bfs::Fletcher16 chk;
  uint8_t test[] = {'a','b','c','d','e'};
  uint16_t result;
  for (std::size_t i = 0; i < sizeof(test); i++) {
    result = chk.Update(&test[i], 1);
  }
  EXPECT_EQ(51440, result);
  EXPECT_EQ(51440, chk.Compute(test, sizeof(test)));
}
