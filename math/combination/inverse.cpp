#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;

int fact[N], infact[N];

int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}

int C(int a, int b) {
    return (LL)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int main() {
    init();
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", C(a, b));
    }
    return 0;
}