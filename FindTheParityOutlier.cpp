// FIND THE PARITY OUTLIER
// https://www.codewars.com/kata/5526fc09a1bbd946250002dc/train/cpp

#include <iostream>
#include <vector>

bool isOdd(int num) { return num % 2 != 0; }

int FindOutlier(std::vector<int> arr) {
  int result;
  bool oddInts;

  if (isOdd(arr[0]) && isOdd(arr[1])) { // arr[0] and arr[1] determine that the array is entirely comprised of odd integers
    oddInts = true;
  } else if (!isOdd(arr[0]) && !isOdd(arr[1])) {  // arr[0] and arr[1] determine that the array is entirely comprised of even integers
    oddInts = false;
  
  // arr[1] and arr[2] are odds/even --> arr[0] is even/odd
  } else if ((isOdd(arr[1]) && isOdd(arr[2])) || (!isOdd(arr[1]) && !isOdd(arr[2]))) { 
    return arr[0];
  }

  if (oddInts) {  // The array is entirely comprise of odd integers
    for (int i = 3; i < arr.size(); ++i) {
      if (!isOdd(arr[i])) {
        return arr[i];
      }
    }
  } else {  // The array is entirely comprise of even integers
    for (int i = 3; i < arr.size(); ++i) {
      if (isOdd(arr[i])) {
        return arr[i];
      }
    }
  }

    
  return -1;
}


int main() {

  std::vector<int> arr1 = {2, 4, 0, 100, 4, 11, 2602, 36};
  std::vector<int> arr2 = {160, 3, 1719, 19, 11, 13, -21};
  std::vector<int> arr3 = {2, 3, 4};
  std::vector<int> arr4 = {1, 2, 3};
  std::vector<int> arr5 = {4, 1, 3, 5, 9};

  std::cout <<"Outlier: " << FindOutlier(arr3) << std::endl;

  return 0;
}


/*
[2, 4, 0, 100, 4, 11, 2602, 36] -->  11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21] --> 160 (the only even number)

test_for({2, 3, 4}, 3);
test_for({1, 2, 3}, 2);
test_for({4, 1, 3, 5, 9}, 4);
      
*/