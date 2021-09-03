#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, m;
int p[N], sz[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) swap(pa, pb);
        p[pb] = pa;
        sz[pa] += sz[pb];
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) merge(a, b);
        else {
            if (find(a) == find(b)) puts("Y");
            else puts("N");
        }
    }
    return 0;
}