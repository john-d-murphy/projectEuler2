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
unsigned long long magicNumber = pow(10,9) + 7;


unsigned long long numberOfPaths(int n, int k) {
  unsigned long long c = 1;
  for (int i = 0; i < k; i++ ) {
     c = c * (n-i) / (i+1);
  }
  return c;
}

int main() {
  int testCases;
  cin >> testCases;
  int n;
  int m;
  for (int i = 1 ; i <= 500 ; i++) {
    for (int j = 1 ; j <= 500; j++) {
      paths[i][j] = numberOfPaths(i+j,j);
    }
  }
  cout << paths[500][500] << endl;
  cout << paths[500][500] % magicNumber << endl;
  cout << paths[20][20] << endl;
  cout << 977899703 % magicNumber << endl;
  cout << magicNumber % 977899703 << endl;

  for (int i = 0 ; i < testCases ; i++ ) {
    int n;
    int m;
    cin >> n >> m;
    unsigned long long result = paths[n][m] % magicNumber;
    cout << result << endl;
  }
}
