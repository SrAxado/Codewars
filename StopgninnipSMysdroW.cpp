// Stop gninnipS My sdroW!
// https://www.codewars.com/kata/5264d2b162488dc400000001/train/cpp

#include <iostream>
#include <string>

std::string spinWords(const std::string &str)
{
  std::string result = str;
  size_t beginWord = 0, endWord = 0;
  
  do {
    std::string word;
    endWord = result.find(' ', beginWord);
    
    if (endWord == std::string::npos) { // Last word with non space character in the end
      endWord = result.size();  // In order to use the endWord to get the final word
    }

    if (endWord - beginWord >= 5) {  // Word with five or more letters
      word = result.substr(beginWord, (endWord - beginWord));
      // std::cout << word << std::endl;        
      
      std::string reversedWord = "";
      for (std::string::reverse_iterator rit = word.rbegin(); rit != word.rend(); ++rit) {
        reversedWord += *rit;
      }
  
      // std::cout << reversedWord << std::endl;
      result.replace(beginWord, reversedWord.size(), reversedWord);
    }


    
    if (endWord != result.size()) {
      if (result[endWord + 1] == ' ') { // If there are consecutive extra spaces
        beginWord = endWord;  // To allow detect and delete a spaces end trail

        do {
          ++endWord;
        } while (result[endWord] == ' ');
        
        if (endWord == result.size()) {  // The last characters of the text are spaces -- we need to delete them
          result.erase(beginWord, std::string::npos);
          break;  // We have reached the end of the text, so we can break the loop
        }
      }
      
      beginWord = ++endWord;  // Positions endWord pointing to the next non space character and points beginWord to it
    } else {
      endWord = std::string::npos;  // Converting endWord to its original value
    }
  } while (endWord != std::string::npos);
  
  return result;
}


std::string spinWords2(const std::string &str) {
  std::string result = "";
  size_t beginWord = 0, endWord = 0;

  for (size_t i = 0; i < str.size(); ++i) {
    endWord = str.find(' ', i);

    if (endWord - i >= 5) {
      for (size_t rit = endWord - 1; rit >= i; --rit) {
        result += str[rit];
      }

      result += str[endWord]; // Adds the space after the reversed word

      // beginWord += endWord - beginWord; // Advances beginWord pointer the word's length
      // i = endWord + 1;  // Advances beginWord pointer the word's length
    
    } else {
      for (size_t it = i; it <= endWord; ++it) {
        result += str[it];
      }
    }
    
    i = endWord;  // Advances i to point to the next word

    if (str[endWord + 1] == ' ') {
      size_t lastSpace = endWord;
      do {  // Searches for a possible spaces end trail and gets to its end
        ++lastSpace;
      } while (str[lastSpace] == ' ');

      if (lastSpace == str.size()) { // It's a spaces end trail -- not to add it to the result
        break;
      
      } else {  // If it's not a spaces end trail, it should add the consecutive spaces to the result
        for (size_t it = i; it < lastSpace; ++it) { // Copies str from i to the lastSpace space character
          result += str[it];
        }
        // result += std::string(' ', lastSpace - endWord);
        i = lastSpace;  //  Points i to the lastSpace character
        continue;
      }
    }

    if (endWord == std::string::npos) { // Last word with non space character in the end
      endWord = str.size();
    }    
  }

  return result;
}


int main() {

  std::string spinnedWordsText;
  // spinnedWordsText = spinWords("Hey fellow warriors");
  spinnedWordsText = spinWords2("This is   a test    ");
  // spinnedWordsText = spinWords2("This is another test");

  std::cout << "'" << spinnedWordsText << "'" << std::endl;

  return 0;
}


/*
"Hey fellow warriors"  --> "Hey wollef sroirraw" 
"This is a test        --> "This is a test" 
"This is another test" --> "This is rehtona test"
*/