int n, m;
double w[N][N];

int gauss() {
    int c, r;
    for (c = 0, r = 0; c < m; c++) {
        int t = r;
        for (int i = r; i < n; i++)
            if (fabs(w[i][c]) > fabs(w[t][c])) t = i;
        if (fabs(w[t][c]) < eps) continue;
        for (int i = c; i <= m; i++) swap(w[t][i], w[r][i]);
        for (int i = m; i >= c; i--) w[r][i] /= w[r][c];
        for (int i = r + 1; i < n; i++)
            if (fabs(w[i][c]) > eps)
                for (int j = m; j >= c; j--) w[i][j] -= w[r][j] * w[i][c]; // ^ for bool gauss
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++)
            if (fabs(w[i][n]) > eps) return 2; // no solutions
        return 1; // infinitely many solutions
    }
    for (int i = n - 1; ~i; i--)
        for (int j = i + 1; j < m; j++) w[i][n] -= w[i][j] * w[j][n]; // ^ for bool gauss
    return 0;
}