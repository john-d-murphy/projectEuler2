
// Recursive Euclid's algorithm -> we'll see if this is actually efficient
int greatestCommonDivisor(int a, int b) {
    int gcd = (b == 0) ? a : greatestCommonDivisor(b, a % b);
    return gcd;
}

int leastCommonMultiple(int a, int b) {
    return (a/greatestCommonDivisor(a,b)) * b;
}
