int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    vector<PQ::point_iterator> its(n + 1, nullptr);
    dist[S] = 0;
    PQ pq;
    pq.push({0, S});
    while (pq.size()) {
        int t = pq.top().y;
        pq.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (its[j] == nullptr) its[j] = pq.push({dist[j], j});
                else pq.modify(its[j], {dist[j], j});
            }
        }
    }
    if (dist[T] == INF) return -1;
    else return dist[T];
}