int tr[M][2];
int root[N], idx;

void insert(int p, int x) {
    int q = ++idx;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (p) tr[q][u ^ 1] = tr[p][u ^ 1];
        tr[q][u] = ++idx;
        p = tr[p][u], q = tr[q][u];
    }
}

// maximum xor
int query(int p, int x) {
    for (int i = 30; i >= 0; i--) {
        int tmp = 1 << i;
        int u = x >> i & 1;
        if (tr[p][u ^ 1]) p = tr[p][u ^ 1], res += tmp;
        else p = tr[p][u];
    }
    return res;
}
