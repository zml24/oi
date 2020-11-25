int lowbit(int x) {
    return x & -x;
}

void add(int tr[], int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int tr[], int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

// range query: tr1: b_i tr2: i * b_i
int pre_sum(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

// all-1 init 
void init() {
    for (int i = 1; i <= n; i++) tr[i] = lowbit(i);
}

// O(n) init
void init() {
    for (int i = 1; i <= n; i++) {
        tr[i] += a[i];
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }
}
