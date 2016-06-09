#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a NxM grid?
As number of ways can be very large, print it modulo 10^9 + 7.

Input Format
The first line contains an integer T, e.g., number of test cases.
Next T lines will contain integers N and M.

Output Format
Print the values corresponding to each test case.

Constraints
1 ≤ T ≤ 10^3
1 ≤ N ≤ 500
1 ≤ M ≤ 500

Sample Input
2
2 2
3 2
Sample Output
6
10
*/

vector< vector<unsigned long long> > paths(501, vector<unsigned long long>(501));
unsigned long long modulo = pow(10,9) + 7;
vector<unsigned long long> factorial(501, 1);

bool outOfBounds(int n, int m) {
    if (n < 0 || m < 0) {
      return true;
    }
    return false;
}

/*
unsigned long long numberOfPaths(int n, int m) {
    unsigned long long pathLength = 0;
    if (n == 0 && m == 0) {
      pathLength = 0;
    } else if (outOfBounds(n,m)) {
      pathLength = 0;
    } else if (n == 1 && m == 0) {
      return 1;
    } else if (n == 0 && m == 1) {
      return 1;
    } else if (paths[n][m] != 0) {
      pathLength = paths[n][m];
    } else {
      pathLength = paths[n][m];
      pathLength = numberOfPaths(n-1,m) + numberOfPaths(n,m-1);
      paths[n][m] = pathLength;
    }
    return pathLength;
}*/

void numberOfPaths(int n, int k) {
  // multiplicative binomial coefficient algorithm
  unsigned long long c = 1;
  for (int i = 0; i < k; i++ ) {
     c = c * (n-i) / (i+1);
  }
  paths[n-k][k] = c;
}

int main() {
  int testCases;
  cin >> testCases;
  int n;
  int m;
  for (int i = 1 ; i <= 500 ; i++) {
    for (int j = 1 ; j <= 500; j++) {
      numberOfPaths(i+j,i);
    }
  }
  cout << paths[500][500] << endl;
  cout << paths[500][500] % modulo << endl;
  cout << paths[20][20] << endl;

  for (int i = 0 ; i < testCases ; i++ ) {
    int n;
    int m;
    cin >> n >> m;
    unsigned long long result = paths[n][m] % modulo;
    cout << result << endl;
  }
}
