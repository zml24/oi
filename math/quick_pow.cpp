#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int qmi(int a, int k, int p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int a, k, p;
    scanf("%d%d%d", &a, &k, &p);
    printf("%d\n", qmi(a, k, p));
    return 0;
}