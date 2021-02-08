# Checksum
This library contains checksum functions and classes.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *checksum*. The header is added as:

```
#include "checksum/checksum.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *checksum_example*, and an executable for testing using the Google Test framework, called *checksum_test*. The example executable source file is located at *examples/checksum_example.cc*.

## Namespace
This library is within the namespace *checksum*.

# Fletcher16
This class implements a [Fletcher16 checksum](https://en.wikipedia.org/wiki/Fletcher%27s_checksum). 

## Methods

**Fletcher16()** Creates a Fletcher16 object and initializes the checksum states.

```C++
checksum::Fletcher16 chk;
```

**uint16_t Compute(uint8_t &ast;data, std::size_t len)** Initializes the checksum states and computes the checksum in a single pass, given a pointer to an array of the data and the length of the array. The result is returned as a 16 bit unsigned integer.

```C++
uint8_t test[] = {'a','b','c','d','e'};
uint16_t result = chk.Compute(test, sizeof(test));
std::cout << result << std::endl;  // 51440
```

**uint16_t Update(uint8_t &ast;data, std::size_t len)** Computes the checksum given a pointer to an array of the data and the length of the array. The result is returned as a 16 bit unsigned integer. Note that this method does not reset the checksum states, enabling it to be used iteratively.

```C++
uint8_t test[] = {'a','b','c','d','e'};
for (std::size_t i = 0; i < sizeof(test); i++) {
   result = chk.Update(&test[i], 1);
}
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
