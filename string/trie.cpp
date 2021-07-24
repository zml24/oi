int tr[N][26], cnt[N], idx;

void init() {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    idx = 0;
}

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

int query(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}
