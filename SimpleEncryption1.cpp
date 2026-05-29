// SIMPLE ENCRYPTION #1
// Given a string S and an integer N, concatenates all the odd-indexed characters of S with all the even-indexed characters of S.
// This process should be repeated N times.
// https://www.codewars.com/kata/57814d79a56c88e3e0000786/train/cpp
#include <iostream>

std::string singlePassEncrypt(std::string text) {
  std::string oddChars = "", evenChars = "";

  // Splits the (text) into odd char positions and even char positions
  for (size_t i = 0; i < text.size(); i += 2) {
    evenChars += text[i];
    if (i + 1 < text.size()) {
      oddChars += text[i + 1];
    }
  }
  return oddChars + evenChars;
}

std::string encrypt(std::string text, int n) {
  if (text.empty() || (n < 0)) {
    return text;
  }

  for (int i = 1; i <= n; ++i) {
    text = singlePassEncrypt(text);
  }
  return text;
}

std::string singlePassDecrypt(std::string text) {
  std::string decryptedText = "";
  // The middle position has to be adjusted
  // const size_t middleTextIdx = (text.size() % 2 == 0) ? (text.size() / 2) : (text.size() / 2);
  const size_t middleTextIdx = text.size() / 2;

  // Alternates chars from the middle position onwards with the beginnig till middle position
  for (size_t i = 0; i <= middleTextIdx; ++i) {
    decryptedText += text[middleTextIdx + i];
    if (i < middleTextIdx) {
      decryptedText += text[i];
    }    
  }
  return decryptedText;
}

std::string decrypt(std::string encryptedText, int n) {
  if (encryptedText.empty() || (n < 0)) {
    return encryptedText;
  }

  for (int i = 1; i <= n; ++i) {
    encryptedText = singlePassDecrypt(encryptedText);
  }
  return encryptedText;
}


int main() {
  // std::cout << encrypt("This is a test!", 3) << std::endl;

  std::string kata = encrypt("This is a test!", 1);
  std::cout << kata << std::endl;
  std::cout << decrypt(kata, 1) << std::endl;
  std::cout << decrypt("1234567890abcde", 1) << std::endl;
  std::cout << decrypt("abcde", 3) << std::endl;
  
  kata = encrypt("This kata is very interesting!", 1);
  std::cout << kata << std::endl;
  std::cout << "'" << decrypt(kata, 1) << "'" << std::endl;

  return 0;
}