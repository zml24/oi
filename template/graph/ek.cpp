bool bfs() {
    memset(st, 0, sizeof st);
    int hh = 0, tt = -1;
    q[++tt] = S, st[S] = true, d[S] = INF;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j] && f[i]) {
                st[j] = true;
                d[j] = min(d[t], f[i]);
                pre[j] = i;
                if (j == T) return true;
                q[++tt] = j;
            }
        }
    }
    return false;
}

int EK() {
    int res = 0;
    while (bfs()) {
        res += d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1])
            f[pre[i]] -= d[T], f[pre[i] ^ 1] += d[T];
    }
    return res;
}
