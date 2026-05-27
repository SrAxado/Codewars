// MUMBLING

/*
Examples:

accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
*/

#include <iostream>

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s) {
  std::string result;

  // Iterate through each character in the input string
  for (size_t i = 0; i < s.size(); ++i) {
    for (size_t j = 0; j <= i; ++j) { //
      if (j == 0) {
        result += std::toupper(s[i]);
      } else {
        result += std::tolower(s[i]);
      }
    }
    result += '-';
  }
  // Remove the trailing '-'
  if (!result.empty()) {
    result.pop_back();
  }
  return result;
}

int main() {

  std::cout << Accumul::accum("cwAt") << std::endl;


  return 0;
}