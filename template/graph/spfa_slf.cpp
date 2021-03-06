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

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;
    deque<int> q;
    q.push_back(S);
    st[S] = true;
    while (hh != tt) {
        int t = q.front();
        q.pop_front();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                // cnt[j] = cnt[t] + 1; // finding negative cycle
                // if (cnt[j] >= j) return -INF;
                if (!st[j]) {
                    if (q.empty() || dist[q.front()] < dist[j]) q.push_back(j);
                    else q.push_front(j);
                    st[j] = true;
                }
            }
        }
    }
    if (dist[T] > INF / 2) return -INF;
    else return dist[T];
}
