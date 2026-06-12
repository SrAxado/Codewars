// Stop gninnipS My sdroW!
// https://www.codewars.com/kata/5264d2b162488dc400000001/train/cpp

#include <iostream>
#include <string>
#include <sstream>  // To be able to run the spinWords3() and spinWords4() -- from Codewars solutions
#include <algorithm>  // To be able to run the spinWords3() and spinWords4() -- from Codewars solutions

std::string spinWords(const std::string &str) { // Replacing the 
  std::string result = str;
  size_t beginWord = 0, endWord = 0;
  
  do {
    std::string word;
    endWord = result.find(' ', beginWord);
    
    if (endWord == std::string::npos) { // Last word with non space character in the end
      endWord = result.size();  // To use endWord to add the final word
    }

    if (endWord - beginWord >= 5) {  // Word with five or more letters
      word = result.substr(beginWord, (endWord - beginWord));
      
      std::string reversedWord = "";
      for (std::string::reverse_iterator rit = word.rbegin(); rit != word.rend(); ++rit) {
        reversedWord += *rit;
      }

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
    }

  } while (endWord != result.size());
  
  return result;
}


std::string spinWords2(const std::string &str) {  // Creating the result string from scratch
  std::string result = "";
  size_t beginWord = 0, endWord = 0;

  for (size_t i = 0; i < str.size(); ++i) {
    endWord = str.find(' ', i);

    if (endWord == std::string::npos) { // Last word with non space character in the end
      endWord = str.size();
    }

    if (endWord - i >= 5) {
      for (size_t rit = endWord - 1; rit >= i; --rit) { // Adds reversed word
        result += str[rit];
      }

    } else {
      for (size_t it = i; it < endWord; ++it) {  // Adds the non reversed word
        result += str[it];
      }
    }
    
    i = endWord;  // Points i to the next word

    if (str[endWord + 1] == ' ') {  // If there are consecutive spaces
      size_t lastSpace = endWord;
      do {  // Searches for a possible spaces end trail and gets to its end
        ++lastSpace;
      } while (str[lastSpace] == ' ');

      if (lastSpace == str.size()) { // It's a spaces end trail -- doesn't add it to the result
        break;
      
      } else {  // If it's not a spaces end trail, it should add the consecutive spaces to the result
        for (size_t it = i; it < lastSpace; ++it) { // Copies str from i to the lastSpace space character
          result += str[it];
        }

        i = lastSpace - 1;  //  Points i to the lastSpace character
        continue;
      }
    } else if (endWord < str.size()) {  // If it didn't process the last word
      result += str[endWord]; // Adds the space after the word and procceeds to the next word
    }
  }

  return result;
}

std::string spinWords3(const std::string &str) {  // Removes inner sentence space trails
    std::stringstream ss(str);
    std::string result;
    std::string buff;
    while (ss >> buff) {
        if (buff.size() >= 5) {
            std::reverse(buff.begin(), buff.end());
        }
        result += buff + ' ';
    }
    result.pop_back();
    return result;
}


std::string spinWords4(const std::string &str) {  // Removes inner sentence space trails
  std::istringstream iss(str);
  std::string w, r;

  while (iss >> w) {
    if (w.length() >= 5) 
      std::reverse(w.begin(), w.end());
      r += w + " ";
  } if (!r.empty())
    r.pop_back();
  
  return r;
}


int main() {

  std::string spinnedWordsText;
  // spinnedWordsText = spinWords3("Hey fellow warriors");
  spinnedWordsText = spinWords3("This is   a test    ");
  // spinnedWordsText = spinWords("This is another test");

  std::cout << "'" << spinnedWordsText << "'" << std::endl;

  return 0;
}


/*
"Hey fellow warriors"  --> "Hey wollef sroirraw" 
"This is a test        --> "This is a test" 
"This is another test" --> "This is rehtona test"
*/