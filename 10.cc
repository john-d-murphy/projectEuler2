#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes not greater than given N .

Input Format
The first line contains an integer T i.e. number of the test cases.
The next T lines will contains an integer N.

Output Format
Print the value corresponding to each test case in seperate line.

Constraints
1 <= T <= 10^4
1 <= N <= 10^6

Sample Input
2
5
10
Sample Output
10
17
-------------------
Submitted a few seconds ago • Score: 100.00 Status: Accepted
Test Case #0:   0s
Test Case #1:   0s
Test Case #2:   0s
Test Case #3:   0s
Test Case #4:   0s
Test Case #5:   0s
Test Case #6:   0.01s
Test Case #7:   0.02s
-------------------
sieveOfEratosthenes and memoization was the key to this puzzle
*/

void sieveOfEratosthenes(int maxInt, bool primes[]) {
  for (int i = 0 ; i < maxInt ; i++) {
    primes[i] = true;
  }

  for (int i = 2; i <= maxInt; i++) {
    if (primes[i] == true) {
      for (int j = i+i; j <= maxInt; j+=i) {
        primes[j] = false;
      }
    }
  }
}


int main() {
  int testCases;
  int testValue;
  long maxValue = 1000001;
  vector<long> sumsAt;
  sumsAt.insert(sumsAt.begin() + 0,0);
  sumsAt.insert(sumsAt.begin() + 1,0);
  sumsAt.insert(sumsAt.begin() + 2,2);
  bool primes[maxValue];
  sieveOfEratosthenes(maxValue, primes);
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    cin >> testValue;
    long long sum = 0;
    // No need to recalculate if we've already seen a number
    if (sumsAt.size() > testValue) {
      sum = sumsAt[testValue];
    } else {
      long long lastEntry = sumsAt.size()-1;
      sum = sumsAt[lastEntry];
      for (long long i = lastEntry+1; i <= testValue; i++ ) {
        if (primes[i] == true) {
          sum += i;
        }
        sumsAt.insert(sumsAt.begin() + i, sum);
      }
    }
    cout << sum << endl;
  }
}
