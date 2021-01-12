void dfs(int u, int bid) {
    id[u] = bid;
    block[bid].push_back(u);
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!id[j]) dfs(j, bid);
    }
}

void dijkstra(int bid) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for (auto u : block[bid]) heap.push({dist[u], u});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int u = t.second;
        if (st[u]) continue;
        st[u] = true;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[u] + w[i]) {
                dist[j] = dist[u] + w[i];
                if (id[j] == id[u]) heap.push({dist[j], j});
            }
            if (id[j] != id[u] && --d[id[j]] == 0) q.push(id[j]);
        }
    }
}

void topsort() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int hh = 0, tt = -1;
    for (int i = 1; i <= bcnt; i++)
        if (!d[i]) q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        dijkstra(t);
    }
}

int main() {
    // add positive edges
    for (int i = 1; i <= n; i++)
        if (!id[i]) dfs(i, ++bcnt);
    // add negative edges
    topsort();
}
