// 0-1 knapsack
for (int i = 1; i <= n; i++)
    for (int j = m; j >= w[i]; j--) f[j] = max(f[j], f[j - w[i]] + v[i]);
