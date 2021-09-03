#include <bits/stdc++.h>

using namespace std;

const int N = 5010, M = 100010, INF = 0x3f3f3f3f;

int n, m, S, T;
int h[N], e[M], f[M], w[M], ne[M], idx;
int q[N], d[N], pre[N], incf[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c, int d) {
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
}

bool spfa() {
    memset(d, 0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    int hh = 0, tt = 0;
    q[tt++] = S, d[S] = 0, incf[S] = INF;
    while (hh != tt) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i] && f[i]) {
                d[j] = d[t] + w[i];
                pre[j] = i;
                incf[j] = min(f[i], incf[t]);
                if (!st[j]) {
                    q[tt++] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    return incf[T] > 0;
}

void EK(int &flow, int &cost) {
    flow = cost = 0;
    while (spfa()) {
        int t = incf[T];
        flow += t, cost += t * d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
}

int min_cost() {
    int flow, cost;
    EK(flow, cost);
    return cost;
}

int max_cost() {
    int flow, cost;
    for (int i = 0; i < idx; i += 2) {
        f[i] += f[i ^ 1], f[i ^ 1] = 0;
        w[i] = -w[i], w[i ^ 1] = -w[i ^ 1];
    }
    EK(flow, cost);
    return -cost;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    init();
    while (m--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(a, b, c, d);
    }
    int flow, cost;
    EK(flow, cost);
    printf("%d %d\n", flow, cost);
    return 0;
}