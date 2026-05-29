// PRODUCT OF CONSECUTIVE FIBONACCI NUMBERS
// https://www.codewars.com/kata/5541f58a944b85ce6d00006a/train/cpp

#include <iostream>
#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod);
};

std::vector<ull> ProdFib::productFib(ull prod) {
  ull fibN = 0;
  ull fibNNext = 1;
  ull prodTmp = 0; // prodFibs = fibN * fibNext;

  do {
    prodTmp = fibN * fibNNext;
    
    // This way ensures that we got the correct fibN and FibNNext, by not stepping to the next Fibonacci values before checking the product between them
    if ((prodTmp == prod) || (prodTmp > prod)) {
      break;

    } else {  // Steps
      ull tmp = fibN;
      fibN = fibNNext;
      fibNNext += tmp;
      // std::swap(fibN, fibNNext);
      // fibNNext += fibN;
    }
  } while ((fibN * fibNNext) <= prod);

  return {fibN, fibNNext, (prodTmp == prod)};
}

int main() {

  std::vector<ull> result = ProdFib::productFib(4895);

  std::cout << result[0] << " " << result[1] << " " << ((result[2] == true) ? "true" : "false") << std::endl;

  return 0;
}