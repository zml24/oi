struct Node {
    int l, r;
    int key, val;
    int sz;
}tr[N];

int root, idx;

void pushup(int p) {
    tr[p].sz = tr[tr[p].l].sz + tr[tr[p].r].sz + 1;
}

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].sz = 1;
    return idx;
}

void split(int p, int &x, int &y, int key) {
    if (!p) x = y = 0;
    else if (tr[p].key <= key) {
        x = p;
        split(tr[p].r, tr[x].r, y, key);
        pushup(p);
    } else {
        y = p;
        split(tr[p].l, x, tr[y].l, key);
        pushup(p);
    }
}

void splitBysz(int p, int &x, int &y, int sz) {
    if (!p) x = y = 0;
    else if (tr[tr[p].l].sz < sz) {
        x = p;
        splitBysz(tr[p].r, tr[p].r, y, sz - tr[tr[p].l].sz - 1);
        pushup(p);
    } else {
        y = p;
        splitBysz(tr[p].l, x, tr[p].l, sz);
        pushup(p);
    }
}

void merge(int &p, int x, int y) {
    if (!x || !y) p = x + y;
    else if (tr[x].val > tr[y].val) {
        p = x;
        merge(tr[p].r, tr[x].r, y);
        pushup(p);
    } else {
        p = y;
        merge(tr[p].l, x, tr[y].l);
        pushup(p);
    }
}

void build() {
    memset(tr, 0, sizeof tr);
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
    int res = tr[x].sz + 1;
    merge(p, x, y);
    return res;
}

int get_key_by_rank(int &p, int rank) {
    if (tr[tr[p].l].sz >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].sz + 1 == rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].sz - 1);
}

int get_prev(int &p, int key) {
    int x = 0, y = 0;
    split(p, x, y, key - 1); // < key
    split(p, x, y, key); // <= key
    int res = get_key_by_rank(x, tr[x].sz);
    merge(p, x, y);
    return res;
}

int get_next(int &p, int key) {
    int x = 0, y = 0;
    split(p, x, y, key); // > key
    split(p, x, y, key - 1); // >= key
    int res = get_key_by_rank(y, 1);
    merge(p, x, y);
    return res;
}
