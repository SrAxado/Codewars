#include <iostream>
#include <string>
#include <vector>

// Inlined implementations from SimpleEncryption1.cpp (no main)

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
  const size_t middleTextIdx = text.size() / 2;
  for (size_t i = 0; i < middleTextIdx; ++i) {
    decryptedText += text[middleTextIdx + i];
    decryptedText += text[i];
  }

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

struct Case { std::string name; std::string got; std::string expected; };

int main() {
  std::vector<Case> cases;

  // Diagnostic: show encrypted example length and chars
  std::string enc_example = encrypt("This kata is very interesting!", 1);
  std::cout << "Encrypted example: '" << enc_example << "' len=" << enc_example.size() << "\n";
  std::cout << "chars: "; for (unsigned char ch : enc_example) std::cout << int(ch) << ' '; std::cout << "\n\n";

  cases.push_back({"encrypt0", encrypt("This is a test!", 0), "This is a test!"});
  cases.push_back({"encrypt1", encrypt("This is a test!", 1), "hsi  etTi sats!"});
  cases.push_back({"encrypt2", encrypt("This is a test!", 2), "s eT ashi tist!"});
  cases.push_back({"encrypt3", encrypt("This is a test!", 3), " Tah itse sits!"});
  cases.push_back({"encrypt4", encrypt("This is a test!", 4), "This is a test!"});
  cases.push_back({"encryptNeg", encrypt("This is a test!", -1), "This is a test!"});
  cases.push_back({"encryptKata1", encrypt("This kata is very interesting!", 1), "hskt svr neetn!Ti aai eyitrsig"});

  cases.push_back({"decrypt0", decrypt("This is a test!", 0), "This is a test!"});
  cases.push_back({"decrypt1", decrypt("hsi  etTi sats!", 1), "This is a test!"});
  cases.push_back({"decrypt2", decrypt("s eT ashi tist!", 2), "This is a test!"});
  cases.push_back({"decrypt3", decrypt(" Tah itse sits!", 3), "This is a test!"});
  cases.push_back({"decrypt4", decrypt("This is a test!", 4), "This is a test!"});
  cases.push_back({"decryptNeg", decrypt("This is a test!", -1), "This is a test!"});
  cases.push_back({"decryptKata1", decrypt("hskt svr neetn!Ti aai eyitrsig", 1), "This kata is very interesting!"});

  cases.push_back({"emptyEncrypt0", encrypt("", 0), ""});
  cases.push_back({"emptyEncrypt3", encrypt("", 3), ""});
  cases.push_back({"emptyDecrypt0", decrypt("", 0), ""});
  cases.push_back({"emptyDecrypt3", decrypt("", 3), ""});

  bool all_ok = true;
  for (auto &c : cases) {
    bool ok = (c.got == c.expected);
    std::cout << (ok ? "OK  : " : "FAIL: ") << c.name << "\n";
    if (!ok) {
      std::cout << "  got     : '" << c.got << "'\n";
      std::cout << "  expected: '" << c.expected << "'\n";
      std::cout << "  got.len : " << c.got.size() << " expected.len: " << c.expected.size() << "\n";
      std::cout << "  got chars: ";
      for (unsigned char ch : c.got) std::cout << int(ch) << ' ';
      std::cout << "\n  expected chars: ";
      for (unsigned char ch : c.expected) std::cout << int(ch) << ' ';
      std::cout << "\n";
      all_ok = false;
    }
  }
  return all_ok ? 0 : 2;
}
