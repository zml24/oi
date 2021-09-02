#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i]) continue;
        primes[cnt++] = i;
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    printf("%d\n", cnt);
    return 0;
}