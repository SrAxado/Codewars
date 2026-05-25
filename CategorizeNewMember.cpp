// CATEGORIZE NEW MEMBER
// https://www.codewars.com/kata/categorize-new-member/train/cpp

#include <iostream>
#include <vector>
#include <utility>
// #include <algorithm> // std::transform

std::vector<std::string> openOrSenior(std::vector<std::pair<int, int>>& data)
{
  auto result = std::vector<std::string>(data.size());
  // Not importing any extra library, we can use a simple for loop to iterate through the data and fill the result vector
  for (size_t i = 0; i < data.size(); ++i) {
    result[i] = ((data[i].first < 55) || (data[i].second <= 7)) ? "Open" : "Senior";
  }

  // If we want to import the "utility" library and use std::transform, here's the way to do it:
  // std::transform(data.begin(), data.end(), result.begin(), [](auto applicant) {
  //  return ((applicant.first < 55) || (applicant.second <= 7)) ? "Open" : "Senior";
  // });

  return result;
}


int main() {

  std::vector<std::pair<int, int>> data   = {{45, 12},{55,21},{19, -2},{104, 20}};
  std::vector<std::pair<int, int>> data2   = {{16, 23},{73,1},{56, 20},{1, -1}};

  auto result = openOrSenior(data);
  for (const auto& r : result) {
    std::cout << r << std::endl;
  }

  /*
  It(example_tests_1)
    {
        std::vector<std::pair<int, int>> data   = {{45, 12},{55,21},{19, -2},{104, 20}};
        std::vector<std::string>         output = {"Open", "Senior", "Open", "Senior"};        
        Assert::That(openOrSenior(data), Equals(output));
    }
    It(example_tests_2)
    {   
        std::vector<std::pair<int, int>> data   = {{16, 23},{73,1},{56, 20},{1, -1}};
        std::vector<std::string>         output = {"Open", "Open", "Senior", "Open"}; 
        Assert::That(openOrSenior(data), Equals(output));
    }
  */

  return 0;
}