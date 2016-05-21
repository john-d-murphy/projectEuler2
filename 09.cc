#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
A Pythagorean triplet is a set of three natural numbers a < b < c for which a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 5^2

Given N, Check if there exists any Pythagorean triplet for which a + b + c = N
Find maximum possible value of abc among all such Pythagorean triplets, If there is no such Pythagorean triplet print -1.

Input Format
The first line contains an integer T i.e. number of test cases.
The next T lines will contain an integer N.

Output Format
Print the value corresponding to each test case in separate lines.

Constraints
1 <= T <= 3000
1 <= N <= 3000

Sample Input
2
12
4
Sample Output
60
-1
*/

int main() {
  int testCases;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    int testValue;
    cin >> testValue;
    long long largestValue = -1;
    // We know:
    //  a < b < c
    //  a^2 + b^2 = c^2
    //  a + b + c = N
    //  Translates to:
    //  c = N - a - b
    //  We can also translate this to:
    //  c = sqrt(a^2 + b^2)
    //  a + b + sqrt(a^2 + b^2) = N
    //  (N - a -b)^2 = (a^2 + b^2)
    //  N^2 - 2N*(a+b) + a^2 + b^2 + 2*a*b = a^2 + b^2
    //  N^2 - 2N*(a+b) + 2*a*b = 0
    //  (N^2/2) - N*(a+b) + a*b = 0
    //  ...
    //  a = ((N^2/2) - (N*b))/(N-b)

    for (int b = 1; b < testValue/2; b++) {
      double a=((testValue*testValue/2.0)-(testValue*b))/(testValue-b);
      if (fmod(a,1.0) == 0.0) {
        int product = (int) (a*b*(testValue-a-b));
        if (product > largestValue) {
          largestValue = product;
        }
      }
    }
    cout << largestValue << endl;
  }
}
