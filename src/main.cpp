#include <print>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <string_view>

int hexProcess(int a, int b){
  return a * 16 + b;
}

int hexDigitValue(char digit){
  if (digit>='0' && digit <= '9')
    return digit - '0';

  if (digit >= 'a' && digit <= 'f')
    return digit - 'a' + 10;

  if (digit >= 'A' && digit <= 'F')
    return digit - 'A' + 10;

  return -1; // invalid hexadecimal character. 
}

std::vector<std::uint8_t>hexToBytes(std::string_view stringData){
  std::string paddedHex(stringData);
  std::vector<std::uint8_t> cleanHexNumbers;

  if (paddedHex.size() % 2 != 0) {
      paddedHex.insert(0,1,'0');
  }
  
for (std::size_t i = 0; i + 1 < paddedHex.size(); i += 2) {
  
  int firstValue = hexDigitValue(paddedHex[i]);
  int secondValue = hexDigitValue(paddedHex[i + 1]);
  
    if (firstValue == -1 || secondValue == -1) {
      throw std::invalid_argument("error, invalid character");
    }

    

    int byteValue = hexProcess(firstValue, secondValue);
  
    cleanHexNumbers.push_back(static_cast<std::uint8_t>(byteValue));
  }

  return cleanHexNumbers;
}
  
 std::vector<std::uint8_t> xorCombination(
   
   const std::vector<std::uint8_t>& a,
   const std::vector<std::uint8_t>& b
 ){

   if (a.size() != b.size()){
     throw std::invalid_argument("Buffers must have equal lengths");
   }

   std::vector<std::uint8_t> result;

   for (std::size_t i = 0; i < a.size();i++){

      result.push_back(a[i] ^ b[i]);
    
   }
  
   return result;
}

std::string bytesToHex(const std::vector<std::uint8_t>& bytes){
  const std::string alphabet16 = "0123456789abcdef";
  std::string result;

  for (std::uint8_t byte : bytes){
    result += alphabet16[byte >> 4];
    result += alphabet16[byte & 0x0f];
  }
  return result;
}

int main(){

auto cleanHexNumbers = hexToBytes("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");



std::string base64Output;

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

for (std::size_t i = 0; i + 2 < cleanHexNumbers.size(); i+=3) {
  auto a = cleanHexNumbers[i];
  auto b = cleanHexNumbers[i+1];
  auto c = cleanHexNumbers[i+2];

  auto group1 = a >> 2 & 0x3f;
  auto group2 = (a & 0x03) << 4 | (b >> 4);
  auto group3 = (b & 0x0f) << 2 | (c >> 6);
  auto group4 = c & 0x3f;

  
base64Output.append({
    alphabet[group1],
    alphabet[group2],
    alphabet[group3],
    alphabet[group4],
});

}


auto task1Hex = bytesToHex(cleanHexNumbers);
std::println ("-----------TASK 1---------\n ");
std::println ("byteValue: {}\n", task1Hex);
std::println ("byteValue: {}\n", cleanHexNumbers);
std::println ("base64: {}\n", base64Output);

// task 1 complete.


/* task 2:

--- Write a function that takes two equal-length buffers and produces their XOR combination.

--- If your function works properly, then when you feed it the string:

--- 1c0111001f010100061a024b53535009181c
--- ... after hex decoding, and when XOR'd against:

--- 686974207468652062756c6c277320657965
--- ... should produce:

--- 746865206b696420646f6e277420706c6179

*/


auto task2HexA = hexToBytes("1c0111001f010100061a024b53535009181c");

auto task2HexB = hexToBytes("686974207468652062756c6c277320657965");

auto task2Xor = xorCombination(task2HexA,task2HexB);

auto task2Result = bytesToHex(task2Xor); 
 
std::println ("-----------TASK 2---------\n");

std::println ("{}\n", task2Result);

}

