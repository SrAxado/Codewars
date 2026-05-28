// ROMAN NUMERALS ENCODER

#include <iostream>
#include <string>
// Defines the Roman Numerals by level (units, tenths, thousands) and pair <single Roman numeral, half level Roman numeral>
// Has there is no standard Roman character for 5000, the limit is 3999 and I paired 'M' with the never used '-'
const std::pair<char, char> romanNumerals[] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', '-'}};

// convert the number to a roman numeral
std::string solution(int number){
  if ((number > 0) && (number < 4000)) {
    std::string romanNum = "";
  
    // Converts each digit to Roman numeration considering the digit's level
    int level = 0;
    do {
      int digit = number % 10;
      number /= 10;
      std::string romanDigit = "";

      if (digit == 0) { // Steps the digit conversion one level up
        ++level;
        continue; // Skips to next's loop iteration

      } else if (digit <= 3) {  // Repeats the first element of the level pair (digit) number of times -- 3 = III
        romanDigit = std::string(digit, romanNumerals[level].first);

      } else if (digit == 4) {  // Places the first element of the level pair element followed by the second element level pair -- 4 = IV
        // By trying to concatenate two chars into a string the easiest way is to convert one char at the time to string
        romanDigit = romanNumerals[level].first;
        romanDigit += romanNumerals[level].second;

      } else if (digit <= 8) {  // Places the second element of the level pair element followed by the first level pair element (digit - 5) number of times -- 8 = VIII
        romanDigit = romanNumerals[level].second + std::string((digit - 5), romanNumerals[level].first);

      } else if (digit == 9) {  // Places the first element of the level pair element followed by the first next level pair element
        // By trying to concatenate two chars into a string the easiest way is to convert one char at the time to string
        romanDigit = romanNumerals[level].first;
        romanDigit += romanNumerals[level + 1].first;
      }

      ++level;  // Steps to the next level
      romanNum.insert(0, romanDigit);

    } while (number > 0);

    return romanNum;

  } else {
    return "Invalid number!";
  }
}


int main() {
  std::cout << solution(3490) << std::endl;

  return 0;
}