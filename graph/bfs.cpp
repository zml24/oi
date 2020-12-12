void bfs() {
    int hh = 0, tt = -1;
    st[1] = true;
    q[++tt] = 1;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                q[++tt] = j;
            }
        }
    }
}
