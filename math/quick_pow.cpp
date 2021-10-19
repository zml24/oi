#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int qmi(LL a, int k, int p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

// LL qmul(LL a, LL k, LL p) {
//     ULL c = (ULL)a * k - (ULL)((long double)a / p * k + 0.5L) * p;
//     return c < p ? c : c + p;
// }

// LL qmi(LL a, LL k, LL p) {
//     LL res = 1;
//     while (k) {
//         if (k & 1) res = qmul(res, a, p);
//         a = qmul(a, a, p);
//         k >>= 1;
//     }
//     return res;
// }

int main() {
    int a, k, p;
    scanf("%d%d%d", &a, &k, &p);
    printf("%d\n", qmi(a, k, p));
    return 0;
}