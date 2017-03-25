#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + .. 10^2 = 385.
The square of the sum of the first ten natural numbers is (1 + 2 ... 10)^2 = 55^2 = 3025.
Hence the difference between the sum of the squares of the first ten natural numbers and the
square of the sum is 3025-385.

Find the difference between the sum of the squares of the first  natural numbers and the square of the sum.

Input Format
First line contains T that denotes the number of test cases. This is followed by N lines, each containing an integer, .

Output Format
Print the required answer for each test case.

Constraints
1 <= T <= 10^4
1 <= N <= 10^4

Sample Input
2
3
10

Sample Output
22
2640
*/

int main() {
  int testCases;
  int testValue;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
      cin >> testValue;
      long squareOfSums = pow(testValue*(testValue+1)/2, 2);
      long sumOfSquares = 0;
      for (int i = 1; i <= testValue; i++) {
          sumOfSquares += pow(i,2);
      }
      cout << squareOfSums - sumOfSquares << endl;
  }
}
