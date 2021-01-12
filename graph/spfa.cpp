int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if (dist[n] == INF) return -1;
    else return dist[n];
}

// slf
int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    deque<int> q;
    q.push_back(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop_front();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    if (q.empty() || dist[q.front()] < dist[j]) q.push_back(j);
                    else q.push_front(j);
                    st[j] = true;
                }
            }
        }
    }
    if (dist[n] == INF) return -1;
    else return dist[n];
}
