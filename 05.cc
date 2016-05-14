#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N ?

Input Format
First line contains T that denotes the number of test cases. This is followed by N lines, each containing an integer, .

Output Format
Print the required answer for each test case.

Constraints
1 <= T < 10
1 <= N <= 40

Sample Input:
2
3
10

Sample Output:
6
2520
------------
English version of theorem that gives the result:
M is divisible by all numbers from 1 to N iff M is equal to the product of all prime powers p^k
where p is prime and divides M, and p < N, and k is the largest integer such that p^k < N.

For example, 2520 = 2^3 * 3^2 * 5 * 7.
*/


int main() {

  int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
  int testCases;
  int testValue;
  cin >> testCases;
  for (int testCase = 0; testCase < testCases ; testCase++ ) {
    cin >> testValue;
    int leastCommonDivisor = 1;
    for (int i = 0 ; primes[i] <= testValue; i++ ) {
      int prime = primes[i];
      int power = 1;
      while (pow(prime, power + 1) <= testValue) {
        power++;
      }
      leastCommonDivisor = leastCommonDivisor * pow(prime,power);
    }
    cout << leastCommonDivisor << endl;
  }
}
