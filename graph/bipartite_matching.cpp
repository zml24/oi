int matching() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }
    return res;
}

int find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
