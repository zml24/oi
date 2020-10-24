int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}
