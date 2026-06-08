#include <iostream>
#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string result = "";
  int pInit = 0;


  do {
    result += std::to_string(args[pInit]);

    if (pInit + 2 < args.size()) {  // Checks if there's the possibility of finding a range of consecutive integers
      int pEnd = pInit + 2; // Points pEnd to the next integer after the minimum range limit
    

      // We calculate both differences so that we don't have to load the <cmath> library
      if ((args[pInit] - args[pEnd] == 2) || (args[pEnd] - args[pInit] == 2)) { // We detected a range of consecutive integers
        int range = 2;  // Confirmed consecutive integers range
        ++pEnd;

        while (((args[pEnd] - args[pInit + range] == 1) || (args[pInit + range] - args[pEnd] == 1)) && (pEnd < args.size())) {
          ++range;
          ++pEnd;
        }

        result += '-' + std::to_string(args[pInit + range]);  // Adds to result the end of the range of consecutive integers found
        pInit = pEnd; // Points pInit to the index of that failed the consecutive integers range or that terminates the main do-while loop
      
      } else {  // It's not a range of consecutive integers
        ++pInit;  // Points pInit to the next index or terminates the main do-while loop
      }
    
    } else { 
      ++pInit;  // Points pInit to the next index or terminates the main do-while loop
    }

    if (pInit < args.size()) {
      result += ',';  // It's not the final integer, adds to result the ',', indicating continuity
    }
  } while (pInit < args.size());

  return result;
}


std::string range_extraction2(const std::vector<int> &args) { // By Slinet6056, Little Slinet, hatruc, coder_macro26692
    auto fast = args.begin(), slow = args.begin();
    std::string ans;
    while (fast != args.end()) {
        while (fast + 1 != args.end() && *(fast + 1) == *fast + 1) ++fast;
        if (fast - slow >= 2) {
            ans += std::to_string(*slow) + "-" + std::to_string(*fast) + ",";
            slow = fast + 1;
            ++fast;
        } else {
            ans += std::to_string(*slow) + ",";
            fast = slow + 1;
            ++slow;
        }
    }
    if (!ans.empty()) ans.pop_back();
    return ans;
}

std::string range_extraction3(std::vector<int> args)  // By kevinbogao
{
    std::string ans = "";

    for (int i = 0, j = 0, n = args.size(); i < n; i++)
    {
        if (args[i] + 1 != args[i + 1])
        {
            if (i != j && args[i] - args[j] > 1)
                ans += std::to_string(args[j]) + '-' + std::to_string(args[i]) +
                       ',';
            else if (i != j)
                ans += std::to_string(args[j]) + ',' + std::to_string(args[i]) +
                       ',';
            else
                ans += std::to_string(args[j]) + ',';

            j = i + 1;
        }
    }

    ans.pop_back();

    return ans;
};



int main() {

  std::vector<int> list1 = {-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}; // "-6,-3-1,3-5,7-11,14,15,17-20"
  std::vector<int> list2 = {-3,-2,-1,2,10,15,16,18,19,20};  // "-3--1,2,10,15,16,18-20"

  std::cout << range_extraction(list1) << std::endl;

  return 0;
}

/*
  Assert::That(range_extraction({-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}), Equals("-6,-3-1,3-5,7-11,14,15,17-20"));
  Assert::That(range_extraction({-3,-2,-1,2,10,15,16,18,19,20}), Equals("-3--1,2,10,15,16,18-20"));
*/