int tr[N][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}

// maximum xor
int query(int x) {
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--) {
        int tmp = 1 << i;
        int u = x >> i & 1;
        if (tr[p][u ^ 1]) p = tr[p][u ^ 1], res += tmp;
        else p = tr[p][u];
    }
    return res;
}
