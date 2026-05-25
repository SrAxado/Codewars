// CATEGORIZE NEW MEMBER
// https://www.codewars.com/kata/categorize-new-member/train/cpp

#include <iostream>
#include <vector>
#include <utility>

std::vector<std::string> openOrSenior(std::vector<std::pair<int, int>>& data)
{
   return {
     std::transform(data.begin(), data.end(), data.begin(), [](auto applicant) {
       std::cout << applicant.first() << " -- " << applicant.second() << std::endl;
       /*
       if ((applicant.first() < 55) || (applicant.second() <= 7)) {
         return "Open";
       } else {
         return "Senior";
       }
       */
      return ((applicant.first() < 55) || (applicant.second() <= 7)) ? "Open" : "Senior";
     })
  }; // TODO: your code here
}


int main() {

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