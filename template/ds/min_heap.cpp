int h[N], ph[N], hp[N], idx, cnt;

void heap_swap(int a, int b) {
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void pushdown(int u) {
    int t = u;
    if (u << 1 <= cnt && h[u << 1] < h[t]) t = u << 1;
    if (u * 2 + 1 <= cnt && h[u << 1 | 1] < h[t]) t = u << 1 | 1;
    if (u != t) {
        heap_swap(u, t);
        pushdown(t);
    }
}

void pushup(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

void init() {
    cnt = idx = 0;
}

// O(n) init
void init(int n) {
    cnt = idx = n;
    for (int i = 1; i <= n; i++) h[i] = w[i];
    for (int i = n / 2; i; i--) pushdown(i);
}

void insert(int x) {
    cnt++, idx++;
    ph[idx] = cnt;
    hp[cnt] = idx;
    h[cnt] = x;
    pushup(cnt);
}

int top() {
    return h[1];
}

void pop() {
    heap_swap(1, cnt);
    cnt--;
    pushdown(1);
}

void remove(int k) {
    k = ph[k];
    heap_swap(k, cnt);
    cnt--;
    pushup(k);
    pushdown(k);
}

void modify(int k, int x) {
    k = ph[k];
    h[k] = x;
    pushup(k);
    pushdown(k);
}
