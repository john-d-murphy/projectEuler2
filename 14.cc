#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
The following iterative sequence is defined for the set of positive integers:
n -> n/2      n is even
n -> 3n + 1   n is odd

Using the rule above and starting with 13, we generate the following sequence:
    13->40->20->10->5->16->8->4->2->1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, <= N produces the longest chain?
If many possible such numbers are there print the maximum one.

Note: Once the chain starts the terms are allowed to go above N.

Input Format
The first line contains an integer T, e.g., number of test cases.
Next T lines will contain an integer N.

Output Format
Print the values corresponding to each test case.

Constraints
1 <= T <= 10^4
1 <= N <= 5*10^6

Sample Input
3
10
15
20

Sample Output
9
9
19 */

long long maxTestValue = 5 * pow(10,6);
//long long maxTestValue = 6;
vector<long long> sequenceLengths(maxTestValue+1);
vector<long long> longestSequence(maxTestValue+1);

long long collatzSequence(long long n) {

  /*
  if (n <= maxTestValue) {
    cout << n << " " ;
  } else {
    cout << "[" << n << "] ";
  } */
  long long sequenceLength = 0;
  long long extraNumbers = 0;

  while (n > maxTestValue) {
    extraNumbers++;
    if (n % 2 == 0) {
      n = n/2;
    } else {
      n = 3*n + 1;
    }
    /*
    if (n <= maxTestValue) {
      cout << n << " " ;
    } else {
      cout << "[" << n << "] ";
    } */
  }

  if (n == 1) {
    sequenceLength = 1;
  } else if (sequenceLengths[n] > 0) {
    //cout << endl << "N: " << n << " Found at " << n << "\tLength: " <<sequenceLengths[n]
    //     << "\tCurrent Length: " << sequenceLength << endl;
    sequenceLength = sequenceLengths[n] + extraNumbers;
  } else if (n % 2 == 0) {
    //cout << endl << "N: " << n << " Seq: "<< sequenceLength << " Recursion into: " << n/2 << endl;
    sequenceLength = 1 + collatzSequence(n/2) + extraNumbers;
    sequenceLengths[n] = sequenceLength;
  } else {
    //cout << endl << "N: " << n << " Seq: "<< sequenceLength << " Recursion into: " << 3*n+1 << endl;
    sequenceLength = 1 + collatzSequence(3*n + 1) + extraNumbers;
    sequenceLengths[n] = sequenceLength;
  }
  //cout << "N: " << n << "\tResult: " << sequenceLength << endl;
  return sequenceLength;
}


int main() {

  long testCases;
  long testValues;
  long size;
  collatzSequence(1);
  longestSequence[1] = 1;
  //cout << endl;
  /*
  cout << "Sequence for 974079" << endl;
  long long slen  = collatzSequence(974079);
  cout << "Length: " << slen << endl;
  cout << "---------------------" << endl;
  return 0;
  */
  //for (long i = 500000; i <= maxTestValue; i++) {
  //for (long i = 950000; i <= 974079; i++) {
  for (long i = 2; i <= maxTestValue; i++) {
  //for (long i = 2; i <= 5; i++) {
    //cout << "Sequence for " << i << ": ";
    long thisSequenceLength = collatzSequence(i);
    sequenceLengths[i] == thisSequenceLength;
    //cout << endl << "Length: " << thisSequenceLength << endl;
    long long previousLargest = longestSequence[i-1];
    if (sequenceLengths[previousLargest] > sequenceLengths[i]) {
      longestSequence[i] = previousLargest;
    } else {
      longestSequence[i] = i;
    }

    if ( i % 10000 == 0 ) {
    cout << "N: " << i << "\tSequence Length: " << sequenceLengths[i] << "\t" \
    << "Longest Sequence: " << longestSequence[i] << "\t" \
    << "Longest Sequence Length: " << sequenceLengths[longestSequence[i]] << endl;
    //sequenceLengths[longestSequence[i]] << " "  << longestSequence[i] << endl;
    }
    //cout << "---------------------" << endl;
    sequenceLengths.clear();

  }
  return 0;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    long long testValue;
    cin >> testValue;
    long long maximumNumber = longestSequence[testValue];
    cout << maximumNumber << endl;
  }
}
