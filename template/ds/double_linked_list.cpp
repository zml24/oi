int e[N], l[n], r[N], idx = 2;

void init() {
    r[0] = 1, l[1] = 0, idx = 2;
}

void insert(int a, int x) {
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx++;
}

void remove(int k) {
    l[r[k]] = l[k], r[l[k]] = r[k];
}
