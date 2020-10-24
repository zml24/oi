// prefix
// 1d: s[i] = s[i - 1] + a[i]
// sum(x1, x2) = s[x2] - s[x1 - 1]

// 2d: s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i][j] + a[i][j]
// sum(x1, x2, y1, y2) = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 2] + s[x1 - 1][y1 - 1]

// difference
// 1d: b[i] = a[i] - a[i - 1]
void insert_1(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

// 2d: b[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]
void insert_2(int x1, int x2, int y1, int y2, int c) {
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
