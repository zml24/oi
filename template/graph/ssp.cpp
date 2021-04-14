bool spfa() {
    memset(d, 0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    queue<int> q;
    q.push(S), d[S] = 0, incf[S] = INF;
    while (hh <= tt) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i] && f[i]) {
                d[j] = d[t] + w[i];
                pre[j] = i;
                incf[j] = min(f[i], incf[t]);
                if (!st[j]) {
                    q.push(j);
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
