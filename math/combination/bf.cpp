#include <bits/stdc++.h>

using namespace std;

const int N = 2010, mod = 1e9 + 7;

int C[N][N];

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {
            if (!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
}

int main() {
    init();
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", C[a][b]);
    }
    return 0;
}