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
  // std::cout << "Size: " << text.size() << " Middle: " << middleTextIdx << std::endl;

  // Alternates chars from the middle position onwards with the ones from the beginnig till the middle position
  for (size_t i = 0; i < middleTextIdx; ++i) {
    decryptedText += text[middleTextIdx + i];
    decryptedText += text[i];
  }

  // If the original text had odd length, append the remaining last character
  if (text.size() % 2 == 1) {
    decryptedText += text[middleTextIdx + middleTextIdx];
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

  // It(EncryptTests)

    encrypt("This is a test!", 0); // it should be equal to "This is a test!"
        encrypt("This is a test!", 1); // It should be equal to "hsi  etTi sats!"
        encrypt("This is a test!", 2); // It should be equal to "s eT ashi tist!"
        encrypt("This is a test!", 3); // It should be equal to " Tah itse sits!"
        encrypt("This is a test!", 4); // It should be equal to "This is a test!"
        encrypt("This is a test!", -1); // It should be equal to "This is a test!"
        encrypt("This kata is very interesting!", 1); // It should be equal to "hskt svr neetn!Ti aai eyitrsig"
    
    // It(DecryptTests)
        decrypt("This is a test!", 0); // It should be equal to "This is a test!"
        decrypt("hsi  etTi sats!", 1); // It should be equal to "This is a test!"
        decrypt("s eT ashi tist!", 2); // It should be equal to "This is a test!"
        decrypt(" Tah itse sits!", 3); // It should be equal to "This is a test!"
        decrypt("This is a test!", 4); // It should be equal to "This is a test!"
        decrypt("This is a test!", -1); // It should be equal to "This is a test!"
        decrypt("hskt svr neetn!Ti aai eyitrsig", 1); // It should be equal to "This kata is very interesting!"
    
    // It(EmptyTests)
        encrypt("", 0); // It should be equal to ""
        encrypt("", 3); // It should be equal to ""
        decrypt("", 0); // It should be equal to ""
        decrypt("", 3); // It should be equal to ""

  return 0;
}

/*

int main() {
  // std::cout << encrypt("This is a test!", 3) << std::endl;

  // std::cout << encrypt("", 2) << std::endl;
  // std::cout << decrypt("", 3) << std::endl;

  // std::string kata = encrypt("This is a test!", 1);
  // std::cout << kata << std::endl;
  // std::cout << decrypt(kata, 1) << std::endl;
  
  // std::cout << (kata = encrypt("1234567890abcde", 1)) << std::endl;
  // std::cout << decrypt(kata, 1) << std::endl;
  
  // std::cout << decrypt("abcde", 3) << std::endl;
  
  std::string kata = encrypt("This kata is very interesting!", 2);
  // std::cout << kata << " (size: " << sizeof(kata) << ")" << std::endl;
  std::string kataDecrypt = decrypt(kata, 2);
  std::cout << "\"" << kataDecrypt << "\"" << std::endl;
  // std::cout << "'" << kataDecrypt << "' (size: " << sizeof(kataDecrypt) << ")" << std::endl;

  return 0;
}
*/



/*
Describe(ExampleTests)
{
    It(EncryptTests)
    {
        Assert::That(encrypt("This is a test!", 0), Equals("This is a test!"));
        Assert::That(encrypt("This is a test!", 1), Equals("hsi  etTi sats!"));
        Assert::That(encrypt("This is a test!", 2), Equals("s eT ashi tist!"));
        Assert::That(encrypt("This is a test!", 3), Equals(" Tah itse sits!"));
        Assert::That(encrypt("This is a test!", 4), Equals("This is a test!"));
        Assert::That(encrypt("This is a test!", -1), Equals("This is a test!"));
        Assert::That(encrypt("This kata is very interesting!", 1), Equals("hskt svr neetn!Ti aai eyitrsig"));
    }
    
    It(DecryptTests)
    {
        Assert::That(decrypt("This is a test!", 0), Equals("This is a test!"));
        Assert::That(decrypt("hsi  etTi sats!", 1), Equals("This is a test!"));
        Assert::That(decrypt("s eT ashi tist!", 2), Equals("This is a test!"));
        Assert::That(decrypt(" Tah itse sits!", 3), Equals("This is a test!"));
        Assert::That(decrypt("This is a test!", 4), Equals("This is a test!"));
        Assert::That(decrypt("This is a test!", -1), Equals("This is a test!"));
        Assert::That(decrypt("hskt svr neetn!Ti aai eyitrsig", 1), Equals("This kata is very interesting!"));
    }
    
    It(EmptyTests)
    {
        Assert::That(encrypt("", 0), Equals(""));
        Assert::That(encrypt("", 3), Equals(""));
        Assert::That(decrypt("", 0), Equals(""));
        Assert::That(decrypt("", 3), Equals(""));
    }
};
*/