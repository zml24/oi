int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
int stk[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(int S, int T) {
    memset(dist, INF, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    dist[S] = 0;
    int tt = 0;
    stk[++tt] = S;
    st[S] = true;
    while (tt) {
        int t = stk[tt--];
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return -INF;
                if (!st[j]) {
                    stk[++tt] = j;
                    st[j] = true;
                }
            }
        }
    }
    if (dist[T] > INF / 2) return -INF;
    else return dist[T];
}
