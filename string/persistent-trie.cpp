int tr[M][26], cnt[M];
int root[N], idx;

// insert str to version q from version p
void insert(char *str, int p, int q) {
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (p)
            for (int j = 0; j < 26; j++)
                if (j != u) tr[q][j] = tr[p][j];
        tr[q][u] = ++idx;
        p = tr[p][u], q = tr[q][u];
        cnt[q] = cnt[p];
    }
    cnt[q]++;
}
 
int query(char *str, int p) {
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}
