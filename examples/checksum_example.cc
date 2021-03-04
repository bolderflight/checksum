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

#include <iostream>
#include "checksum/checksum.h"

int main() {
  /* Checksum object */
  bfs::Fletcher16 chk;
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
