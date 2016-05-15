#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Find the greatest product of K consecutive digits in the N digit number.

Input Format
First line contains T that denotes the number of test cases.
First line of each test case will contain two integers N & K.
Second line of each test case will contain a N digit integer.

Output Format
Print the required answer for each test case.

Constraints
1 <= T <= 100
1 <= K <= 7
K <= N <= 1000

Sample Input

2
10 5
3675356291
10 5
2709360626

Sample Output

3150
0 */

int main() {
  int testCases;
  string testNumber;
  int testLength;
  int testDigits;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    cin >> testLength >> testDigits >> testNumber;
    long maxNumber = 0;
    for(int i = 0; i < testLength - testDigits; i++) {
      long currentNumber = 1;
      for(int j = 0; j < testDigits; j++) {
        // ASCII digits start at value 48, so 0 will be 48,
        // and subtracting will give us the appropriate value
        currentNumber = currentNumber * (testNumber.at(i+j) - 48);
      }
      if (currentNumber > maxNumber) {
        maxNumber = currentNumber;
      }
    }
    cout << maxNumber << endl;
  }
}
