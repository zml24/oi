#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int mod;

int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

int C(int a, int b) {
    if (a < b) return 0;
    int down = 1, up = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        down = (LL)down * i % mod;
        up = (LL)up * j % mod;
    }
    return (LL)up * qmi(down, mod - 2) % mod;
}

int lucas(LL a, LL b) {
    if (a < mod && b < mod) return C(a, b);
    return (LL)C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        LL a, b;
        scanf("%lld%lld%d", &a, &b, &mod);
        printf("%d\n", lucas(a, b));
    }
    return 0;
}