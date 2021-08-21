#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 200010;
const int INF = 0x3f3f3f3f;

int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
int q[N], dist[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    int hh = 0, tt = 0;
    q[tt++] = S, dist[S] = 0;
    while (hh != tt) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                // finding negative cycle
                // cnt[j] = cnt[t] + 1;
                // if (cnt[j] >= j) return true;
                if (!st[j]) {
                    q[tt++] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    if (dist[T] > INF / 2) puts("impossible");
    else printf("%d\n", dist[T]);
}

int main() {
    init();
    scanf("%d%d%d%d", &n, &m, &S, &T);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    spfa();
    return 0;
}