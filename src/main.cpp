#include <print>
#include <string>
#include <vector>
#include <cstddef>


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

int main(){

const std::string stringData = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

std::string_view view(stringData);


std::vector<int> cleanHexNumbers = {};

int byteValue = 0;

for (std::size_t i = 0; i + 1 < stringData.size(); i += 2) {
  
  int firstValue = hexDigitValue(stringData[i]);
  int secondValue = hexDigitValue(stringData[i + 1]);
  
    if (firstValue == -1 || secondValue == -1) {
      std::println("error, invalid character");
      return 1;
    }
    

    byteValue = hexProcess(firstValue, secondValue);
  
    cleanHexNumbers.push_back(byteValue);
}

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



std::println ("the string:\n {}\n", stringData);
std::println ("byteValue: {}\n", cleanHexNumbers);
std::println ("base64: {}\n", base64Output);

}

