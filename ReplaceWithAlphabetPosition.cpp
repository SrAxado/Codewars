// REPLACE WITH ALPHABET POSITION
// https://www.codewars.com/kata/replace-with-alphabet-position/train/cpp

#include <iostream>
#include <string>
#include <vector>


// Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements 
// with the same value next to each other and preserving the original element's order.

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> finalList;
  
  if (iterable.size() > 0) {
    for (int i = 0; i < iterable.size(); ++i) {  // Loop over the iterable string
      int j = i + 1;  // Get the next element's index
      while ((iterable[j] == iterable[i]) && (j < iterable.size())) {  // Loop until the next element is different from the current one
        j++;
      }
      finalList.push_back(iterable[i]);  // Add the current element to the final list
      i = j - 1;  // Points i to the last known duplicate (so that the next loop iteration will point to the next different element)
    }
  }
  return finalList;
}

std::vector<char> uniqueInOrder(const std::string& iterable){
  std::	vector<char> finalList; // This will be the list to be shared, filled and returned in the end
  
  if (iterable.size() > 0) {
    for (int i = 0; i < iterable.size(); ++i) {  // Loop over the iterable string
      int j = i + 1;  // Get the next element's index
      while ((iterable[j] == iterable[i]) && (j < iterable.size())) {  // Loop until the next element is different from the current one
        j++;
      }
      finalList.push_back(iterable[i]);  // Add the current element to the final list
      i = j - 1;  // Points i to the last known duplicate (so that the next loop iteration will point to the next different element)
    } 
  }
  return finalList;
}


/*
// Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements 
// with the same value, presenving the original element's order.

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> finalList; // This will be the list to be shared, filled and returned in the end
  
  if (iterable.size() > 0) {
    for (auto it : iterable) {  // Loop over the iterable string
      if (finalList.size() > 0) { // Checks if the it is already in the finalList
        if (std::find(finalList.begin(), finalList.end(), it) == finalList.end()) {  // It doesn't exist in the finalList
          finalList.push_back(it);
          // std::cout << it << std::endl;
        }
      } else {  // The finalist is empty, so we can add the first element without checking
        finalList.push_back(it);
        // std::cout << it << std::endl;
      }
    }
  }
  
  return finalList;
}

std::vector<char> uniqueInOrder(const std::string& iterable){
  std::	vector<char> finalList; // This will be the list to be shared, filled and returned in the end
  
  if (iterable.size() > 0) {
    for (auto it : iterable) {  // Loop over the iterable string
      if (finalList.size() > 0) { // Checks if the it is already in the finalList
        if (std::find(finalList.begin(), finalList.end(), it) == finalList.end()) {  // It doesn't exist in the finalList
          finalList.push_back(it);
          // std::cout << it << std::endl;
        }
      } else {  // The finalist is empty, so we can add the first element without checking
        finalList.push_back(it);
        // std::cout << it << std::endl;
      }
    } 
  }
  
  return finalList;
}

*/

int main() {
  std::string testString = "AAAABBBCCDAABBB";
  std::vector<char> result = uniqueInOrder(testString);
  std::vector<int> testVector = {1, 2, 2, 3, 3};
  std::vector<int> result2 = uniqueInOrder(testVector);
  
  for (auto it : result) {
    std::cout << it << std::endl;
  }
  
  return 0;
}