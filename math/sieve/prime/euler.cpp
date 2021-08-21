#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    get_primes(n);
    printf("%d\n", cnt);
    return 0;
}