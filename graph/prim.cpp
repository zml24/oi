int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) res += dist[t];
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
        st[t] = true;
    }
    return res;
}
