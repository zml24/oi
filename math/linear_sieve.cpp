int primes[N];
bool st[N];

int get_primes(int n) {
    memset(primes, 0, sizeof primes);
    memset(st, 0, sizeof st);
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[res++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    return res;
}
