#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const double eps = 1e-4;

int n, m;
double w[N][N];

int gauss(double w[][N]) {
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
                for (int j = m; j >= c; j--) w[i][j] -= w[r][j] * w[i][c];
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++)
            if (fabs(w[i][n]) > eps) return -1; // No solutions
        return 1;                               // Infinitely group solutions
    }
    for (int i = n - 1; ~i; i--)
        for (int j = i + 1; j < m; j++) w[i][n] -= w[i][j] * w[j][n];
    return 0;
}

int gauss(int w[][N]) {
    int c, r;
    for (c = 0, r = 0; c < m; c++) {
        int t = r;
        for (int i = r; i < n; i++)
            if (w[i][c]) {
                t = i;
                break;
            }
        if (!w[t][c]) continue;
        for (int i = c; i <= m; i++) swap(w[t][i], w[r][i]);
        for (int i = r + 1; i < n; i++)
            for (int j = m; j >= c; j--) w[i][j] ^= w[r][j] & w[i][c];
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++)
            if (w[i][n]) return -1; // No solutions
        return 1;                   // Multiple sets of solutions
    }
    for (int i = n - 1; ~i; i--)
        for (int j = i + 1; j < m; j++) w[i][n] ^= w[i][j] & w[j][n];
    return 0;
}

int main() {
    scanf("%d", &n);
    m = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++) scanf("%lf", &w[i][j]);
    int t = gauss(w);
    if (t == 1) puts("Infinite group solutions");
    else if (t == -1) puts("No solution");
    else {
        for (int i = 0; i < n; i++) printf("%.2f\n", w[i][m]);
    }
    return 0;
}