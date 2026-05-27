// PLAYING WITH DIGITS
// https://www.codewars.com/kata/5552101f47fc5178b1000050/train/cpp

#include <iostream>
// I'll try my best not to load any extra libraries

/*
89 --> 8¹ + 9² = 89 * 1
695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2
46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

n = 89; p = 1 ---> 1 since 8¹ + 9² = 89 = 89 * 1

n = 92; p = 1 ---> -1 since there is no k such that 9¹ + 2² equals 92 * k

n = 695; p = 2 ---> 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2

n = 46288; p = 3 ---> 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
*/

class DigPow
{
  public:
    static int digPow(int n, int p);

  private:
    static int numberOfDigits(int const n);
    static int power(int base, int exponent);
    
};

// I created this function before loading the iostream library
int DigPow::numberOfDigits(int n) {
  int nDigits = 0;

  do {
    int digit = n % 10;
    n /= 10;
    ++nDigits;
  } while (n > 0);

  return nDigits;
}

// In order not to load any extra libraries, I created this function to calculate the power of a number
int DigPow::power(int base, int exponent) {
  int result = 1;

  for (int i = 0; i < exponent; ++i) {
    result *= base;
  }

  return result;
}


int DigPow::digPow(int n, int p) {
  std::string nString = std::to_string(n);
  int sumRaised = 0;

  // Calculate the sum of the digits raised to the p+i power successively
  for (size_t i = 0; i < nString.size(); ++i) {
    sumRaised += power(nString[i] - '0', p + i);
  }
  
  // if there is a value that satisfies the equation sumRaised = n * t, return t, else return -1
  return (sumRaised % n == 0) ? sumRaised / n : -1;
}



int main() {
  DigPow digPow;
  std::cout << digPow.digPow(46288, 3) << std::endl;


  return 0;
}


/*
It(Fixed__Tests)
    {
      dotest(89, 1, 1);
      dotest(92, 1, -1);
      dotest(46288, 3, 51);
      dotest(114, 3, 9);
    }
*/