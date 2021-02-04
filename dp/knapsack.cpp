// 0-1 knapsack
for (int i = 0; i < n; i++)
    for (int j = m; j >= v; j--) f[j] = max(f[j], f[j - v] + w);

// unbounded knapsack
for (int i = 0; i < n; i++)
    for (int j = v; j <= m; j++) f[j] = max(f[j], f[j - v] + w);

// O(nmlogs): bounded knapsack with binary lifting
for (int i = 0; i < n; i++) {
    for (int k = 1; k <= s; s -= k, k *= 2)
        for (int j = m; j >= k * v; j--) f[j] = max(f[j], f[j - k * v] + k * w);
    if (s)
        for (int j = m; j >= s * v; j--) f[j] = max(f[j], f[j - s * v] + s * w);
}

// O(nm): bounded knapsack with monotonous queue
for (int i = 0; i < n; i++) {
    memcpy(g, f, sizeof f);
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
