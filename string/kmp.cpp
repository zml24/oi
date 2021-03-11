char s[n + 1], p[m + 1]; // index from 1
int ne[N];

void build() {
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
}

int query() {
    int res = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
            res++;
            j = ne[j];
        }
    }
    return res;
}
