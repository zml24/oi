#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000010;

int primes[N], cnt;
int phi[N];
bool st[N];

LL init(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) res += phi[i];
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", init(n));
    return 0;
}