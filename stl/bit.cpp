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

// number to binary string
string s = bitset<N>(x).to_string();
s.erase(0, s.find_first_of('1'));
