bool check() {
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--) num[i] = num[i] << 1 | a[i][j]; // line[i]
    for (int st = 0; st < 1 << n; st++) {
        int tmp = 0;
        for (int i = 1; i <= n; i++)
            if ((1 << i - 1) & st) { // choose line[i]
                if (tmp & num[i]) break;
                tmp |= num[i];
            }
        if (tmp == (1 << n) - 1) return true;
    }
    return false;
}
