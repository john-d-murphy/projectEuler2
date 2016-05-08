#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Problem Description:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

HackerRank:
Find the sum of all the multiples of 3 or 5 below N.

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format
For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below NN.

Constraints
1≤T≤10^5
1≤N≤10^9

*/

long sumUnderValue(long difference, long valueToFindUnder) {
  long numberOfTerms = (valueToFindUnder - 1)/difference;
  long firstValue = difference;
  long lastValue = numberOfTerms * difference;
  long sumUnderValue = (numberOfTerms * (firstValue + lastValue))/2;
  return sumUnderValue;
}

int main() {
  int testCases;
  long n;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    while (cin >> n ) {
      long sum = sumUnderValue(3,n) + sumUnderValue(5,n) - sumUnderValue(15,n);
      cout << sum << endl;
    }
  }
  return 0;
}
