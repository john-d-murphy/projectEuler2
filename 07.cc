#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7 and 13 , we can see that the 6th prime is 13.
What is the Nth prime number?

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format
Print the required answer for each test case.

Constraints
1 <= T <= 10^3
1 <= N <= 10^4

Sample Input
2
3
6
Sample Output
5
13

-------------

To solve, I used trial division with memoization.

*/

bool isValuePrime(int testValue, vector<int> knownPrimes) {
  int i = 0;
  int max = sqrt(testValue);
  for(int i = 0; knownPrimes[i] <= max; i++) {
    if (testValue % knownPrimes[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int testCases;
  int testValue;
  vector<int> primes;
  primes.push_back(2);
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    cin >> testValue;
    for(int potentialPrime = primes.back()+1; primes.size() <= testValue; potentialPrime++) {
      if (isValuePrime(potentialPrime, primes)) {
        primes.push_back(potentialPrime);
      }
    }
    cout << primes[testValue-1] << endl;
  }
}
