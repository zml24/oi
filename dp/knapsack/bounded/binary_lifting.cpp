int f[M];

for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &w, &v, &s);
    for (int k = 1; k <= s; s -= k, k *= 2)
        for (int j = m; j >= k * v; j--) f[j] = max(f[j], f[j - k * v] + k * w);
    if (s)
        for (int j = m; j >= s * v; j--) f[j] = max(f[j], f[j - s * v] + s * w);
}
