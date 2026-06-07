// FIND THE PARITY OUTLIER
// https://www.codewars.com/kata/5526fc09a1bbd946250002dc/train/cpp

#include <iostream>
#include <vector>

constexpr bool isOdd(int num) noexcept { return num % 2 != 0; }

int FindOutlier(std::vector<int> arr) {
  int result;
  bool oddParity;

  // if (isOdd(arr[0]) && isOdd(arr[1])) { // arr[0] and arr[1] determine that the array is entirely comprised of odd integers
  //   oddParity = true;
  // } else if (!isOdd(arr[0]) && !isOdd(arr[1])) {  // arr[0] and arr[1] determine that the array is entirely comprised of even integers
  //   oddParity = false;
  
  // Finds the general array parity by analyzing its first three elements
  if (isOdd(arr[0]) && isOdd(arr[1]) || (!isOdd(arr[0]) && !isOdd(arr[1]))) {
    oddParity = isOdd(arr[0]);  // Two equal parity elements tells us if the general parity is odd or even

  // Tries to find the general array parity by analyzing arr[0] and arr[2]
  } else if ((isOdd(arr[0]) && isOdd(arr[2])) || (!isOdd(arr[0]) && !isOdd(arr[2]))) {
    oddParity = isOdd(arr[0]);

  // Tries to find the general array parity by analyzing arr[1] and arr[2]
  } else if ((isOdd(arr[1]) && isOdd(arr[2])) || (!isOdd(arr[1]) && !isOdd(arr[2]))) {
    oddParity = isOdd(arr[1]);
  }
  

  // Seeks through the array for the parity outlier 
  for (int i = 0; i < arr.size(); ++i) {
    if (oddParity) {  // The general parity is odd
      if (!isOdd(arr[i])) return arr[i];  // Returns the even value
    
    } else {  // The general parity is even
      if (isOdd(arr[i])) return arr[i]; // Returns the odd value
    }
  }
    
  return -1;
}


#include <cmath>
int FindOutlier2(std::vector<int> arr)  // By 算痞子
{
    if ((abs(arr[0]) + abs(arr[1])) % 2 == 0 )  //前两数同奇同偶  // (even, even), (odd, odd)
    {
        int mod = abs(arr[0]) % 2;  // main parity
        for (int var : arr)
        {
            if (abs(var) % 2 != mod)
                return var;
        }
    }
    else  //前两数一奇一偶  (even, odd), (odd, even)
    {
        int mod = abs(arr[2]) % 2;  // main parity
        if (abs(arr[0]) % 2 != mod)
            return arr[0];
        else
            return arr[1];
    }
    return -1;
}


#define LAST(x) ((x) & 1)

int FindOutlier3(std::vector<int> arr)  // By rubs33
{
  char lastBit = (LAST(arr[0]) + LAST(arr[1]) + LAST(arr[2])) > 1 ? 0 : 1;
  
  for (int val: arr) if (LAST(val) == lastBit) return val;

  return 0;
}


int main() {

  std::vector<int> arr1 = {2, -4, 0, 100, 4, 11, 2602, 36};
  std::vector<int> arr2 = {160, -3, 1719, 19, 11, 13, -21};
  std::vector<int> arr3 = {2, 3, 4};
  std::vector<int> arr4 = {1, 2, 3};
  std::vector<int> arr5 = {4, 1, 3, 5, 9};
  std::vector<int> arr6 = {2, 4, 3};
  std::vector<int> arr7 = {1, -1, 2};

  std::cout <<"Outlier: " << FindOutlier2(arr7) << std::endl;

  return 0;
}


/*
[2, 4, 0, 100, 4, 11, 2602, 36] -->  11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21] --> 160 (the only even number)

test_for({2, 3, 4}, 3);
test_for({1, 2, 3}, 2);
test_for({4, 1, 3, 5, 9}, 4);
      
*/