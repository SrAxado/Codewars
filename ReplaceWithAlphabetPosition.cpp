#include <iostream>
#include <string>

std::string alphabet_position(const std::string &text) {
  std::string position_text = "";
  
  for (auto c : text) {
    // We'll only consider the letters, discarding the numbers and the ponctuation
    if (isalpha(c)) {
      // Converting all letters to lowercase, we'll consider the letter 'a' as the baseline value 1
      position_text += std::to_string(int(std::tolower(c)) - int('a') + 1) + ' ';
//      std::cout << position_text << std::endl;
    }
  }
  // If a new string was created, then we'll have to remove the last character as it is a space
  if (position_text.size() > 0) { // All of the following options are valid solutions
    position_text.pop_back();
//    position_text.resize(position_text.size() - 1);
//  return position_text.substr(0, position_text.size() - 1);
  }
  
  return position_text;
}


int main() {
  std::string text = "The sunset sets at twelve o' clock.";
  std::cout << "Returned:\n" << alphabet_position(text) << std::endl;  
  std::cout << "Should return: \n20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" << std::endl;
  
  return 0;
}