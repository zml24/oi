#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

bool miller_rabin(int n) {
    if (n < 3 || n % 2 == 0) return n == 2;
    int a = n - 1, b = 0;
    while (a % 2 == 0) a /= 2, b++;
    for (int i = 1, j; i <= 8; i++) {
        int x = rand() % (n - 2) + 2, v = qmi(x, a, n);
        if (v == 1) continue;
        for (j = 0; j < b; j++) {
            if (v == n - 1) break;
            v = (LL)v * v % n;
        }
        if (j >= b) return 0;
    }
    return 1;
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        int n;
        scanf("%d", &n);
        if (miller_rabin(n)) puts("Yes");
        else puts("No");
    }
    return 0;
}