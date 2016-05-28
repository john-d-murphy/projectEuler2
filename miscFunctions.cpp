
// Recursive Euclid's algorithm -> we'll see if this is actually efficient
int greatestCommonDivisor(int a, int b) {
    int gcd = (b == 0) ? a : greatestCommonDivisor(b, a % b);
    return gcd;
}

int leastCommonMultiple(int a, int b) {
    return (a/greatestCommonDivisor(a,b)) * b;
}

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
