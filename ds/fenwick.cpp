// 1-index
int n;
int tr[N];

int lowbit(int x) {
    return x & -x;
}

void init() {
    memset(tr, 0, sizeof tr);
}

// all-1 init 
void init() {
    for (int i = 1; i <= n; i++) tr[i] = lowbit(i);
}

// O(n) init
void init() {
    memset(tr, 0, sizeof tr);
    for (int i = 1; i <= n; i++) {
        tr[i] += a[i];
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }
}

void add(int tr[], int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int tr[], int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

void range_add(int l, int r, int d) {
    add(tr1, l, d), add(tr1, r + 1, -d);
    add(tr2, l, l * d), add(tr2, r + 1, (r + 1) * -d);
}

int range_sum(int l, int r) {
    return sum(tr1, r) * (r + 1) - sum(tr2, r) - sum(tr1, l - 1) * l + sum(tr2, l - 1);
}
