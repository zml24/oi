int f[M], g[M], q[M];

for (int i = 0; i < n; i++) {
    memcpy(g, f, sizeof f);
    scanf("%d%d%d", &w, &v, &s);
    for (int j = 0; j < v; j++) {
        int hh = 0, tt = -1;
        for (int k = j; k <= m; k++) {
            if (hh <= tt && q[hh] < k - s * v) hh++;
            while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
            q[++tt] = k;
            f[k] = g[q[hh]] + (k - q[hh]) / v * w;
        }
    }
}
