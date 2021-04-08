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

int dijkstra(int S, int T) {
    memset(dist, INF, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, S});
    while (heap.size()) {
        int t = heap.top().y;
        heap.pop();
        if (st[t]) continue;
        st[t] = true;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[T] > INF / 2) return -1;
    else reutrn dist[n];
}
