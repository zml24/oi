// __builtin_popcount(x): the number of 1
// __builtin_clz(x): the number of leading 0
// __builtin_ctz(x): the number of trailing 0

int lowbit(n) {
    return n & -n;
}
