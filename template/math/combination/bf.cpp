const int N = 2010;

int c[N][N];

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
}

int get(int a, int b) {
    return c[a][b];
}
