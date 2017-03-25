#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
n! means n x (n - 1) x ... x 3 x 2 x 1
For example 10! = 10 x 9 x ... x 3 x 2 x 1 = 362880,
and the sum of the digits in the number 10! = 3 + 6 + 2 + 8 + 8 + 0 = 27

Find the sum of the digits in the number N!

Input format:

The first line contains an integer T, e.g. the number of test cases
The next T lines will contain an integer N.

Constraints:

* 1 <= T <= 100
* 0 <= N <= 1000

Output Format:

Print the values corresponding to each test case

Sample Input

2
3
6
Sample Output

6
9
*/

vector<vector<int>> factorials(10000);
vector<long> sumOfDigits(1000);

vector<int> multiplyByValue(vector<int> value, int multiplier) {
  int overflow = 0;
  vector<int> newValue;
  int vectorSize = value.size();

  for(int i = 0; i < vectorSize; i++ ) {

    // Get what this digit's multiplied value is
    int multiple = value[i] * multiplier;

    // Add it to our current working overflow
    int placeValue = overflow + multiple;
    int digit = placeValue % 10;

    // Get new overflow value
    overflow = (placeValue - placeValue % 10)/10;

    // Prepend new digit
    newValue.push_back(digit);
  }

  while(overflow > 0) {
    int digit = overflow % 10;
    newValue.push_back(digit);
    overflow = overflow / 10;
  }
}

int main() {
  for( int i = 1; i <=

}
