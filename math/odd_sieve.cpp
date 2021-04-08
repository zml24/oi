int primes[N];
bool st[N];

int get_primes(int n) {
    memset(primes, 0, sizeof primes);
    memset(st, 0, sizeof st);
    int res = 0;
    if (n < 2) return res;
    primes[res++] = 2;
    for (int i = 3; i <= n / i; i += 2) {
        if (!st[i])
            for (int j = i; j <= n / i; j += 2) st[i * j] = true;
    }
    for (int i = 3; i <= n; i += 2) 
        if (!st[i]) primes[res++] = i;
    return res;
}
