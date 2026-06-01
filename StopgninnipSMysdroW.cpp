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
      std::cout << word << std::endl;        
      
      std::string reversedWord = "";
      for (std::string::reverse_iterator rit = word.rbegin(); rit != word.rend(); ++rit) {
        reversedWord += *rit;
      }
  
      std::cout << reversedWord << std::endl;
      result.replace(beginWord, reversedWord.size(), reversedWord);
    }


    
    if (endWord != result.size()) {
      if (result[endWord + 1] == ' ') { // If there are consecutive extra spaces
        beginWord = endWord;  // To allow detect and delete a spaces end trail

        do {
          ++endWord;
        } while (result[endWord + 1] == ' ');
        
        if (endWord == std::string::npos) {  // The last characters of the text are spaces -- we need to delete them
          result.erase(beginWord, std::string::npos);
        }
      }
      
      beginWord = ++endWord;  // Positions endWord pointing to the next non space character and points beginWord to it
    } else {
      endWord = std::string::npos;  // Converting endWord to its original value
    }
  } while (endWord != std::string::npos);
  
  return result;
}


int main() {

  std::string spinnedWordsText = spinWords("Hey fellow warriors");
  spinnedWordsText = spinWords("This is a test    ");

  std::cout << "'" << spinnedWordsText << "'" << std::endl;

  return 0;
}


/*
"Hey fellow warriors"  --> "Hey wollef sroirraw" 
"This is a test        --> "This is a test" 
"This is another test" --> "This is rehtona test"
*/