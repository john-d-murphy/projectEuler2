#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
2^9 is 518 and the sum of its digits is 5 + 1 + 2 = 8.

What is the sum of the digits of the number 2^N ?

Input Format
The first line contains an integer T , i.e., number of test cases.
Next N lines will contain an integer N.

Output Format
Print the values corresponding to each test case.

Constraints
1 <= T <= 100
1 <= N <= 10^4

Sample Input
3
3
4
7
Sample Output
8
7
11 */

vector<vector<int>> powersOfTwo(10000);
vector<long> sumOfDigits(10000);

vector<int> multiplyByTwo(vector<int> value) {
  int overflow = 0;
  vector<int> newValue;
  int vectorSize = value.size();
  for (int i = 0; i < vectorSize; i++) {

    // Get what this digit's double is
    int multiple = value[i] * 2;

    // Add it to our current working overflow
    int placeValue = overflow + multiple;
    int digit = placeValue % 10;

    // Get new overflow value
    overflow = (placeValue - placeValue % 10)/10;

    // Prepend new digit
    newValue.push_back(digit);
  }

  if (overflow > 0) {
    newValue.push_back(overflow);
  }

  newValue = newValue;

  return newValue;
}

long sumDigits(int powerOfTwo) {
  vector<int> value = powersOfTwo[powerOfTwo];
  long sum = 0;
  for (int i = 0; i < value.size(); i++) {
    sum += value[i];
  }
  return sum;
}

int main() {
  // Precompute
  powersOfTwo[0].push_back(1);
  for (int i = 1 ; i <= 10000; i++) {
    vector<int> value = powersOfTwo[i-1];
    powersOfTwo[i] = multiplyByTwo(value);
    sumOfDigits[i] = sumDigits(i);
  }

  // Run TestCases
  int testCases;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    int testValue;
    cin >> testValue;
    cout << sumOfDigits[testValue] << endl;
  }
}
