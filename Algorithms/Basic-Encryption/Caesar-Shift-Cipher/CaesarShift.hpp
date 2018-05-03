#ifndef CAESAR_SHIFT_HPP
#define CAESAR_SHIFT_HPP
#include <string>
class CaesarShifter{
public:
  CaesarShifter(const std::string& _text, const int& _shiftBy);
  void encrypt();
  void decrypt();
  std::string getText();
private:
  void shift(const int& sh);
private:
  std::string text;  // ciphertext/plaintext saved here...
  int shiftBy;
};
#endif /* CAESAR_SHIFT_CPP */
