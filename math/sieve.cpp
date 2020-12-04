bool st[N];

// linear
int primes[N];

int get_primes(int n) {
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

// odd
int get_primes(int n) {
    if (n < 2) return 0;
    int res = 1;
    for (int i = 3; i * i <= n; i += 2)
        if (!st[i])
            for (int j = i; i * j <= n; j += 2) st[i * j] = true;
    for (int i = 3; i <= n; i += 2) res += (!st[i]);
    return res;
}
