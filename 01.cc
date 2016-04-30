#include <iostream>
#include <cmath>

// As simple as you can do it - fizz buzz

int main() {
    int i = 0;
    int sum = 0;
    for (i = 3; i < 1000 ; i++) {
      if (i % 3 == 0) {
        sum += i;
      } else if (i % 5 == 0) {
        sum += i;
      }
    }
    std::cout << sum << std::endl;
    std::cin.get();
    return 0;
}
