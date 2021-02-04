// get the number of 1
int get(int x) {
    return __builtin_popcount(x);
}

// get the number of leading 0
int get(int x) {
    return __builtin_clz(x);
}

// get the number of trailing 0
int get(int x) {
    return __builtin_ctz(x);
}

// get length in O(1)
int get_len(int x) {
    return 32 - __biiltin_clz(x);
}
