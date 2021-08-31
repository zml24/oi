#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

LL lcm(int a, int b) {
    return (LL)a * b / gcd(a, b);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %lld\n", gcd(a, b), lcm(a, b));
    return 0;
}