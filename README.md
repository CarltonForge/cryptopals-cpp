# Cryptopals - C++

Working through the [Cryptopals Crypto Challenges](https://cryptopals.com/) using C++.

This is mainly a learning project. I'm using the challenges to improve my understanding of C++, bitwise operations, data representation and cryptography.

I'm working through each challenge myself and trying to understand what's happening under the hood rather than just getting something that works.

## Progress

### Set 1 - Basics

- [x] Challenge 1 - Convert hex to Base64
- [x] Challenge 2 - Fixed XOR
- [ ] Challenge 3 - Single-byte XOR cipher
- [ ] Challenge 4 - Detect single-character XOR
- [ ] Challenge 5 - Implement repeating-key XOR
- [ ] Challenge 6 - Break repeating-key XOR
- [ ] Challenge 7 - AES in ECB mode
- [ ] Challenge 8 - Detect AES in ECB mode

## Building

Requires a C++23 compiler and CMake.

```bash
cmake -S . -B build
cmake --build build
./build/cryptopals
```

More challenges will be added as I work through the sets.
