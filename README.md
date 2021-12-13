[![Pipeline](https://gitlab.com/bolderflight/software/checksum/badges/main/pipeline.svg)](https://gitlab.com/bolderflight/software/checksum/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Checksum
This library contains clases and methods for computing common checksums. This library is compatible with Arduino ARM and with CMake build systems. It would also be easy to include with other projects, since it is a header only library consisting of a single file.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Installation

## Arduino
Use the Arduino Library Manager to install this library or clone to your Arduino/libraries folder. This library is added as:

```C++
#include "checksum.h"
```

An example Arduino executable is located at *examples/arduino/checksum_example/checksum_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other ARM devices. This library is *not* expected to work on AVR devices.

## CMake
CMake is used to build this library, which is exported as a library target called *checksum*. The header is added as:

```C++
#include "checksum.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *checksum_example*, and an executable for testing using the Google Test framework, called *checksum_test*. The example executable source file is located at *examples/cmake/checksum_example.cc*.

# Namespace
This library is within the namespace *bfs*.

# Fletcher16
This class implements a [Fletcher16 checksum](https://en.wikipedia.org/wiki/Fletcher%27s_checksum). 

## Methods

**Fletcher16()** Creates a Fletcher16 object and initializes the checksum states.

```C++
bfs::Fletcher16 chk;
```

**uint16_t Compute(uint8_t const &ast; const data, const std::size_t len)** Initializes the checksum states and computes the checksum in a single pass, given a pointer to an array of the data and the length of the array. The result is returned as a 16 bit unsigned integer.

```C++
uint8_t test[] = {'a','b','c','d','e'};
uint16_t result = chk.Compute(test, sizeof(test));
std::cout << result << std::endl;  // 51440
```

**uint16_t Compute(const std::array<uint8_t, N> &ref)** Same as the previous *Compute* method, but takes a reference to a *std::array* as input rather than a pointer and a length.

```C++
std::array<uint8_t, 5> test = {'a','b','c','d','e'};
uint16_t result = chk.Compute(test);
std::cout << result << std::endl;  // 51440
```

**uint16_t Update(uint8_t const &ast; const data, const std::size_t len)** Computes the checksum given a pointer to an array of the data and the length of the array. The result is returned as a 16 bit unsigned integer. Note that this method does not reset the checksum states, enabling it to be used iteratively.

```C++
uint8_t test[] = {'a','b','c','d','e'};
for (std::size_t i = 0; i < sizeof(test); i++) {
   result = chk.Update(&test[i], 1);
}
std::cout << result << std::endl;  // 51440
```

**uint16_t Update(const std::array<uint8_t, N> &ref)** Same as the previous *Update* method, but takes a reference to a *std::array* as input rather than a pointer and a length.

```C++
std::array<uint8_t, 5> test = {'a','b','c','d','e'};
uint16_t result = chk.Update(test);
std::cout << result << std::endl;  // 51440
```

**void Reset()** This method resets the checksum states. It should be used in conjunction with the Update method to reset states in between different checksum computations.

```C++
uint8_t test[] = {'a','b','c','d','e'};
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
```
