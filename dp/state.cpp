// O(3^n) searching
for (int i = 0; i < 1 << n; i++)
    for (int j = i; j; j = (j - 1) & i)
        f[i] = f[i - j] + w[j];
