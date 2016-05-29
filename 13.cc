#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
Work out the first ten digits of the sum of N 50-digit numbers.

Input Format
First line contains N, next N lines contain a 50 digit number each.

Output Format
Print only first 10 digit of the final sum

Constraints
1 <= N <= 10^3

Sample Input

5
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
Sample Output

2728190129
*/

int main() {
  int testCases;
  vector<string> testValues;
  cin >> testCases;
  // Populate Test cases
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    string testValue;
    cin >> testValue;
    testValues.push_back(testValue);
  }

  //Sum the test cases
  long overFlow = 0;
  string sum = "";
  for (int i = 49 ; i >= 0 ; i--) {
    int placeSum = 0;
    // Sum the values for each test case
    for (int testCase = 0; testCase < testCases; testCase++) {
      string testValue = testValues[testCase].substr(i,1);
      placeSum += stoi(testValue);
    }
    // Get the values for each digit
    placeSum += overFlow;
    int digit = placeSum % 10;
    overFlow = (placeSum - placeSum % 10)/10;
    sum = to_string(digit) + sum;
  }

  // now that we are finished, let's prepend the overflow digit
  sum = to_string(overFlow) + sum;
  cout << sum.substr(0,10) << endl;
}
