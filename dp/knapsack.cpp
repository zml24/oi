// 0-1 knapsack
for (int i = 1; i <= n; i++)
    for (int j = m; j >= w[i]; j--) f[j] = max(f[j], f[j - w[i]] + v[i]);

// unbounded knapsack
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= m; j++) f[j] = max(f[j], f[j - w[i]] + v[i]);

// bounded knapsack
for (int i = 1; i <= n; i++) {
    memcpy(g, f, sizeof f);
    for (int j = 0; j < v[i]; j++) {
        int hh = 0, tt = -1;
        for (int k = j; k <= m; k++) {
            if (hh <= tt && q[hh] < k - s * v[i]) hh++;
            while (hh <= tt && g[q[tt]] - (q[tt] - j) / v[i] * w[i] <= g[k] - (k - j) / v[i] * w[i]) tt--;
            q[++tt] = k;
            f[k] = g[q[hh]] + (k - q[hh]) / v[i] * w[i];
        }
    }
}
