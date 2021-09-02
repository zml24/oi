#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], d[N], ne[M], idx;
int q[N];

void init() {
    memset(h, -1, sizeof h);
    memset(d, 0, sizeof d);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, d[b]++, ne[idx] = h[a], h[a] = idx++;
}

bool topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0) q[++tt] = j;
        }
    }
    return tt == n - 1;
}

void print() {
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    puts("");
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    if (topsort()) print();
    else puts("-1");
    return 0;
}