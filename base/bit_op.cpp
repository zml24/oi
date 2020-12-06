// __builtin_popcount(x): the number of 1
// __builtin_clz(x): the number of leading 0
// __builtin_ctz(x): the number of trailing 0

// lowbit
int lowbit(n) {
    return n & -n;
}

// get length in O(n)
int g[N + 1];

for (int i = 1; i <= n; i++) g[i] = g[i / 2] + 1;

// get length in O(1)
int get_len(int x) {
    return 32 - __biiltin_clz(x);
}
