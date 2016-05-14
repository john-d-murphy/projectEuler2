#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the
product of two 3-digit numbers is 101101=143×707.

Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
*/

bool isPalindrome(int numberToCheck) {
  int reversedNumber = 0;
  int tempNumber = numberToCheck;
  while (tempNumber > 0) {
    reversedNumber = (reversedNumber * 10) + (tempNumber % 10);
    tempNumber = tempNumber/10;
  }
  return (reversedNumber == numberToCheck);
}

int numberOfDigits(int numberToCheck) {
  return floor(log10(numberToCheck)) + 1;
}


vector<int> getPalindromes() {
  vector<int> palindromes;

  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      int potentialPalindrome = i * j;
      if (numberOfDigits(potentialPalindrome) == 6 && isPalindrome(potentialPalindrome)) {
        palindromes.push_back(potentialPalindrome);
      }
    }
  }
  sort(palindromes.begin(), palindromes.end());
  return palindromes;
}

int main() {
  vector<int> palindromes = getPalindromes();
  int testCases;
  long testValue;

  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    cin >> testValue;
    int palindromeValue = 0;
    for (int i = 0; i < palindromes.size(); i++) {
        if (palindromes[i] < testValue) {
          palindromeValue = palindromes[i];
        } else {
          break;
        }
    }
    cout << palindromeValue << endl;
  }
}
