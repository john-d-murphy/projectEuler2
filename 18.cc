#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23. The path is 3->7->4->9.

    3
   7 4
  2 4 6
 8 5 9 3

 Find the maximum total from top to bottom of the triangle given in input.

 Input Format
 First line contains T, the number of testcases. For each testcase:
 First line contains N, the number of rows in the triangle.
 For next N lines, i'th line contains i numbers.

 Output Format
 For each testcase, print the required answer in a newline.

Constraints
1 <= T <= 10
1 <= N <= 15
numbers in [0,100]

Sample input

1
4
3
7 4
2 4 6
8 5 9 3
Sample output

23
*/

bool outOfBounds(int x, int y, int maxX, int maxY) {
  if (x < 0 || y < 0) {
    return true;
  } else if (x > maxX || y > maxY) {
    return true;
  } else {
    return false;
  }
}

long getMaxPath(vector<vector<int>> tree, int treeLevel, int column) {

  long maxPath;

  // The tree will have 'treeLevel' amount of columns
  if (outOfBounds(column, treeLevel, treeLevel, tree.size()-1)) {
    maxPath = 0;
  } else {
    long currentValue = tree[column][treeLevel];
    int left = getMaxPath(tree, treeLevel + 1, column);
    int right = getMaxPath(tree, treeLevel + 1, column + 1);
    maxPath = max(left,right) + currentValue;
  }
  return maxPath;
}

int main() {
  int testCases;
  cin >> testCases;
  for (int i = 0 ; i < testCases ; i++) {
    int numberOfTreeLevels;
    cin >> numberOfTreeLevels;
    // Populate tree
    vector<vector<int>> tree(numberOfTreeLevels+1, vector<int>(numberOfTreeLevels+1));
    for (int treeLevel = 1; treeLevel <= numberOfTreeLevels; treeLevel++) {
      for (int column = 1; column <= treeLevel; column++) {
        cin >> tree[column][treeLevel];
      }
    }
    // With tree populated, get max path starting from the root
    long maxPath = getMaxPath(tree, 1, 1);
    cout << maxPath << endl;
  }
}
