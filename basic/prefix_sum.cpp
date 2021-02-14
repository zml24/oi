// 1d prefix sum
void init() {
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
}

int sum(int l, int r) {
    return s[r] - s[l - 1];
}

// 2d prefix sum
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
}

int sum(int x1, int x2, int y1, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y2 - 1] + s[x1 - 1][y1 - 1];
}

// 1d difference
void init() {
    for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
}

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

// 2d difference
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]
}

void insert(int x1, int x2, int y1, int y2, int c) {
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
