// BUILD TOWER
// Build a pyramid-shaped tower given the number of floors.

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
  std::vector<std::string> result;
  // The length of the base is (nFloors - 1) * 2 + 1
  int halfBaseLength = (nFloors - 1); // Calculate the length of the half base of the floor (minus the center *)

  for (int i = 0; i < nFloors; ++i) {
    std::string halfFloor = "";
    for (int j = 1; j <= halfBaseLength; ++j) {
      if (j <= halfBaseLength - i) {
        halfFloor += " ";
      } else {
        halfFloor += "*";
      }
    }
    // Create the full floor by combining the half floor with its reverse and a center *
    std::string fullFloor = halfFloor + "*" + std::string(halfFloor.rbegin(), halfFloor.rend());

    result.push_back(fullFloor);
  }
  return result;
}

// Alternative implementation using string constructor and concatenation
std::vector<std::string> towerBuilder2(unsigned nFloors) {
  std::vector<std::string> tower;
  for(unsigned i = 0, k = 1; i < nFloors; ++i, k+=2)
    tower.push_back(std::string(nFloors-i-1, ' ') + std::string(k, '*') + std::string(nFloors-i-1, ' '));
  return {tower};
}

// Another simplified implementation using string constructor and concatenation
std::vector<std::string> towerBuilder3(unsigned nFloors) {
  std::vector<std::string> tower;
  for(unsigned i = 0; i < nFloors; ++i)
    tower.push_back(std::string(nFloors-i-1, ' ') + std::string(i*2+1, '*') + std::string(nFloors-i-1, ' '));
  return tower;
}

int main()  {
  std::vector<std::string> tower = towerBuilder3(3);

  for (const auto& floor : tower) {
    std::cout << "'" << floor << "'" << std::endl;
  }

  return 0;
}