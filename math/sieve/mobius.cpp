#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int primes[N], cnt;
bool st[N];
int mobius[N], sum[N];

void init(int n) {
    mobius[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            mobius[i] = -1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                mobius[t] = 0;
                break;
            }
            mobius[t] = mobius[i] * -1;
        }
    }
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + mobius[i];
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    printf("%d\n", sum[n]);
    return 0;
}