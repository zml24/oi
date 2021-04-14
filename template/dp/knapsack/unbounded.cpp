int f[M];

for (int i = 0; i < n; i++) {
    scanf("%d%d", &w, &v);
    for (int j = v; j <= m; j++) f[j] = max(f[j], f[j - v] + w);
}
