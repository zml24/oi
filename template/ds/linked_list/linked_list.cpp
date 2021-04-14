int head, e[N], ne[N], idx;

void init() {
    head = -1, idx = 0;
}

void add(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

void insert(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int k) {
    if (!k) head = ne[head];
    else ne[k] = ne[ne[k]];
}
