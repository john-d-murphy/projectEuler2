#include <iostream>
#include <cmath>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;

/*
Problem:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
----------------

Simplest thing to do here is use trial division starting from 2.

*/

int main() {
  long long numberToFactorize = 600851475143LL;
  int trialNumber = 2;
  cout << "Number to Factorize" << numberToFactorize << endl;
  while (numberToFactorize > 1) {
      if ((numberToFactorize % trialNumber) == 0 ) {
        numberToFactorize = numberToFactorize/trialNumber;
        cout << trialNumber << " divides evenly" << endl;
      } else {
        trialNumber++;
      }
  }
  cin.get();
}
