#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = log2(N) + 1;

int n, m;
int w[N];
int f[N][M];

void init(int l, int r) {
    for (int j = 0; j < M; j++)
        for (int i = l; i + (1 << j) - 1 <= r; i++)
            if (!j) f[i][j] = w[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    init(1, n);
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}