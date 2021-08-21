#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL qmi(LL a, int k, int p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    LL a;
    int k, p;
    scanf("%lld%d%d", &a, &k, &p);
    printf("%d\n", qmi(a, k, p));
    return 0;
}