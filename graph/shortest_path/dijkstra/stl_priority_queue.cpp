#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 100010, M = 100010;

int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, S});
    while (pq.size()) {
        int t = pq.top().y;
        pq.pop();
        if (st[t]) continue;
        st[t] = true;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                pq.push({dist[j], j});
            }
        }
    }
    if (dist[T] == INF) return -1;
    else return dist[T];
}
