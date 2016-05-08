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

What is the largest prime factor of a given number N?

*/

long largestPrimeFactor(long numberToFactorize) {
  long trialNumber = 2;
  double maxValue = sqrt(numberToFactorize);

  /* we only need to divide up to the sqrt of the number to
     factorize - we get to this point and we can make a
     decision as to which number is the prime. */
  while (numberToFactorize > 1 && trialNumber <= maxValue) {
      if ((numberToFactorize % trialNumber) == 0 ) {
        numberToFactorize = numberToFactorize/trialNumber;
      } else {
        trialNumber++;
      }
  }

  /* Now we have two numbers, one that's divisible by 2 and
     one that's a prime number. We need to determine which is
     which. */
  if (numberToFactorize / 2 != 0) {
    return numberToFactorize;
  } else {
    return trialNumber;
  }
}

int main() {
  int testCases;
  long testValue;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    cin >> testValue;
    cout << largestPrimeFactor(testValue) << endl;
  }
}
