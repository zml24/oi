# single linked list
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

# double linked list
int e[N], l[n], r[N], idx = 2;

void init() {
    r[0] = 1, l[1] = 0, idx = 2;
}

void insert(int a, int x) {
    e[idx] = x;
    l[idx] = a;
    r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx++;
}

void remove(int k) {
    l[r[k]] = l[k], r[l[k]] = r[k];
}
