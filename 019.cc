

/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month between two dates(both inclusive)?

Input Format

The first line contains an integer T, i.e., number of test cases.
Each testcase will contain two lines
Y1 M1 D1 on first line denoting starting date.
Y2 M2 D2 on second line denoting ending date.

Constraints

* 1 <= T <= 100
* 1900 <= Y1 <= 10^16
* Y1 <= Y2 <= (Y1 + 1000)
* 1 <= M1, M2 <= 12
* 1 <= D1, D2 <= 31

Output Format

Print the values corresponding to each test case.

Sample Input

2
1900 1 1
1910 1 1
2000 1 1
2020 1 1
Sample Output

18
35
*/

int startYear = 1900;
int startMonth = 1;
int startDay = 1;

long calculateDaysInEpoch(int year, int month, int day) {
  int years = year - startYear;
  int months = month - startMonth;
  int days = day - startDay;
}


int main() {
  int testCases;
  cin >> testCases;

  for( int i = 0; i < testCases; i++) {

      int year1 , year2, month1, month2, day1, day2;
      cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;
  }
}



