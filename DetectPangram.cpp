// DETECT PANGRAM
// https://www.codewars.com/kata/545cedaa9943f7fe7b000048/train/cpp

#include <iostream>
#include <string>
#include <set>

bool is_pangram(const std::string& s) {
  // char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  //                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w','x', 'y', 'z'};

  // bool detectPangram[sizeof(alphabet) / sizeof(alphabet[0])];

  const int numAlphabetLetters = 26;
  bool detectPangram[numAlphabetLetters] = {false};

  for (char c : s) {
    if (isalpha(c)) {
      detectPangram[tolower(c) - 'a'] = true;
    }
  }

  for (bool i : detectPangram) {
    if (i != true) {
      return false;
    }
  }

  return true;
}

bool is_pangram2(const std::string& s) { // By PureMathcoder
  std::set<char> set{};
  for(auto& element : s){
    if(std::isalpha(element)){
      set.insert(std::tolower(element));
    }
  }
  return set.size() == 26;
}


int main() {

  if (is_pangram2("The quick, brown fox jumps over the lazy dog!")) {
  // if (is_pangram("a2cdefghijklmnopqrstuvwxyz")) {
  // if (is_pangram("a2cdefghijnopqtuvwxyz")) {
    std::cout << "All are letters accounted for!" << std::endl;
  } else {
    std::cout << "Not all letters are accounted for!" << std::endl;
  }

  
  return 0;
}

/*
  Assert::That(is_pangram("The quick, brown fox jumps over the lazy dog!"), Equals(true));
  Assert::That(is_pangram("1bcdefghijklmnopqrstuvwxyz"), Equals(false));
*/