int tr[M][2];
int root[N], idx;

void init() {
    memset(tr, 0, sizeof tr);
    memset(root, 0, sizeof root);
    idx = 0;
}

void insert(int x, int i, int j) {
    int p = root[i], q = root[j] = ++idx;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (p) tr[q][u ^ 1] = tr[p][u ^ 1];
        tr[q][u] = ++idx;
        p = tr[p][u], q = tr[q][u];
    }
}

int query_xor(int x, int i) {
    int res = 0, p = root[i];
    for (int i = 30; i >= 0; i--) {
        int tmp = 1 << i;
        int u = x >> i & 1;
        if (tr[p][u ^ 1]) p = tr[p][u ^ 1], res += tmp;
        else p = tr[p][u];
    }
    return res;
}
