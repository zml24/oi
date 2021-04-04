struct Node {
    int l, r;
    int key, val;
    int size;
}tr[N];

int root, idx;

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
}

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].size = 1;
    return idx;
}

void split(int p, int &a, int &b, int key) {
    if (!p) a = b = 0;
    else if (tr[p].key <= key) {
        a = p;
        split(tr[p].r, tr[a].r, b, key);
        pushup(p);
    } else {
        b = p;
        split(tr[p].l, a, tr[b].l, key);
        pushup(p);
    }
}

void merge(int &p, int a, int b) {
    if (!a || !b) p = a + b;
    else if (tr[a].val > tr[b].val) {
        p = a;
        merge(tr[p].r, tr[a].r, b);
        pushup(p);
    } else {
        p = b;
        merge(tr[p].l, a, tr[b].l);
        pushup(p);
    }
}

void build() {
    idx = 0;
    int x = get_node(-INF), y = get_node(INF);
    root = 1;
    merge(root, x, y);
}

void insert(int &p, int key) {
    int x = 0, y = 0, z = get_node(key);
    split(p, x, y, key);
    merge(x, x, z);
    merge(p, x, y);
}

void remove(int &p, int key) {
    int x = 0, y = 0, z = 0;
    split(p, x, y, key);
    split(x, x, z, key - 1);
    merge(z, tr[z].l, tr[z].r);
    merge(x, x, z);
    merge(p, x, y);
}

int get_rank_by_key(int &p, int key) {
    int x = 0, y = 0;
    split(p, x, y, key - 1);
    int res = tr[x].size + 1;
    merge(p, x, y);
    return res;
}

int get_key_by_rank(int &p, int rank) {
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + 1 == rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - 1);
}

int get_prev(int &p, int key) {
    int x = 0, y = 0;
    split(p, x, y, key - 1); // < key
    split(p, x, y, key); // <= key
    int res = get_key_by_rank(x, tr[x].size);
    merge(p, x, y);
    return res;
}

int get_next(int &p, int key) {
    int x = 0, y = 0;
    split(p, x, y, key); // > key
    split(p, x, y, key - 1); // > key
    int res = get_key_by_rank(y, 1);
    merge(p, x, y);
    return res;
}
