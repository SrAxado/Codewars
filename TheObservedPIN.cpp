// THE OBSERVED PIN
// https://www.codewars.com/kata/5263c6999e0f40dee200059d
#include <iostream>
#include <string>
#include <vector>

// Defines the possible digit combinations according to the observed digit
std::vector<std::string> possibleCombinations(char observedDigit) {
  switch ((observedDigit - '0')){
    case 0:
      return {"0", "8"};
    case 1:
      return {"1", "2", "4"};
    case 2:
      return {"1", "2", "3", "5"};
    case 3:
      return {"2", "3", "6"};
    case 4:
      return {"1", "4", "5", "7"};
    case 5:
      return {"2", "4", "5", "6", "8"};
    case 6:
      return {"3", "5", "6", "9"};
    case 7:
      return {"4", "7", "8"};
    case 8:
      return {"0", "5", "7", "8", "9"};
    case 9:
      return {"6", "8", "9"};
    
    default:
      return {};
  }
}

std::vector<std::string> get_pins(std::string observed) {
  std::vector<std::string> result;

  for (int i = observed.size() - 1; i >= 0; --i) { // Scans the observed digits in reverse order, from last to first
    
    if (i == observed.size() - 1) { // Last digit observed
      result = possibleCombinations(observed[i]);
      
    } else {  // All other observed digits
      std::vector<std::string> intermediateResult, possibleDigits;
    
      possibleDigits = possibleCombinations(observed[i]); // Get's the possible digits of the current observed digit
      intermediateResult.swap(result);  // "Empty's" the result vector to fill it with new found possibilities

      for (auto digit : possibleDigits) {
        for (auto intRes : intermediateResult) {
          result.push_back(digit + intRes);
        }
      }
    }
  }
  return result;
}


#include <array>
#include <numeric>

const static std::array<std::string, 10> possibilities = {  // By de-passage
  "08", "124", "1235", "236", "1457", "24568", "3569", "478", "57890", "689"
};

std::vector<std::string> generate_next_sequence(const std::vector<std::string>& strings, char c) {  // By de-passage
  const int value = c - '0';
  std::vector<std::string> results;
  results.reserve(sizeof(strings) * sizeof(possibilities[value]));
  
  for (const auto& str : strings) {
    for (char c : possibilities[value]) {
      results.push_back(str + c);
    }
  }
  
  return results;
}

std::vector<std::string> get_pins2(std::string observed) {  // By de-passage
  return std::accumulate(std::begin(observed), std::end(observed), std::vector<std::string>{{""}}, generate_next_sequence);
}



int main() {

    std::vector<std::string> possibilites = get_pins("369");

    for (auto possibility : possibilites) {
      std::cout << possibility << "  ";
    }

    std::cout << std::endl << std::endl;

  return 0;
}


/*
  std::vector<std::string> output = get_pins("8"); std::sort(output.begin(), output.end());
  std::vector<std::string> result = {"0", "5", "7", "8", "9"};
  Assert::That(output, Equals(result));
  
  output = get_pins("11"); std::sort(output.begin(), output.end());
  result = {"11", "12", "14", "21", "22", "24", "41", "42", "44"};
  Assert::That(output, Equals(result));
  
  output = get_pins("369"); std::sort(output.begin(), output.end());
  result = {"236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339", "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659", "666", "668", "669", "696", "698", "699"};
  Assert::That(output, Equals(result));
*/