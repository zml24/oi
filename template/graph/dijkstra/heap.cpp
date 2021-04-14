int n, m, S, T;
int h[N], w[N], e[N], ne[N], idx;
int heap[N], ph[N], hp[N], heap_idx, cnt;
int dist[N];
int st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void heap_swap(int a, int b) {
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}

void pushdown(int u) {
    int t = u;
    if (u << 1 <= cnt && dist[heap[u << 1]] < dist[heap[t]]) t = u << 1;
    if (u * 2 + 1 <= cnt && dist[heap[u << 1 | 1]] < dist[heap[t]]) t = u << 1 | 1;
    if (u != t) {
        heap_swap(u, t);
        pushdown(t);
    }
}

void pushup(int u) {
    while (u / 2 && dist[heap[u]] < dist[heap[u / 2]]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

void init() {
    cnt = heap_idx = 0;
}

void insert(int x) {
    cnt++, heap_idx++;
    ph[heap_idx] = cnt;
    hp[cnt] = heap_idx;
    heap[cnt] = x;
    pushup(cnt);
}

void pop() {
    heap_swap(1, cnt);
    cnt--;
    pushdown(1);
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    init();
    dist[S] = 0;
    insert(S);
    st[S] = heap_idx;
    while (cnt) {
        int t = heap[1];
        pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (st[j]) {
                    j = ph[st[j]];
                    pushup(j);
                } else {
                    insert(j);
                    st[j] = heap_idx;
                }
            }
        }
    }
    if (dist[T] == INF) return -1;
    return dist[T];
}
