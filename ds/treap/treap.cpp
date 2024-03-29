#include <bits/stdc++.h>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int m;

struct Node {
    int l, r;
    int key, val;
    int cnt, sz;
}tr[N];

int root, idx;

void pushup(int p) {
    tr[p].sz = tr[tr[p].l].sz + tr[tr[p].r].sz + tr[p].cnt;
}

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].sz = 1;
    return idx;
}

void zig(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r), pushup(p);
}

void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l), pushup(p);
}

void build() {
    memset(tr, 0, sizeof tr);
    idx = 0;
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);
    if (tr[1].val < tr[2].val) zag(root);
}

void insert(int &p, int key) {
    if (!p) p = get_node(key);
    else if (tr[p].key == key) tr[p].cnt++;
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}

void remove(int &p, int key) {
    if (!p) return;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);
            } else {
                zag(p);
                remove(tr[p].l, key);
            }
        } else p = 0;
    } else if (tr[p].key > key) remove(tr[p].l, key);
    else remove (tr[p].r, key);
    pushup(p);
}

int get_rank_by_key(int &p, int key) {
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].sz + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].sz + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}

int get_key_by_rank(int &p, int rank) {
    if (!p) return INF;
    if (tr[tr[p].l].sz >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].sz + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].sz - tr[p].cnt);
}

int get_prev(int &p, int key) {
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    // if (tr[p].key > key) return get_prev(tr[p].l, key); // <= key
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int &p, int key) {
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    // if (tr[p].key < key) return get_next(tr[p].r, key); // >= key
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main() {
    scanf("%d", &m);
    build();
    while (m--) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) insert(root, x);
        else if (op == 2) remove(root, x);
        else if (op == 3) printf("%d\n", get_rank_by_key(root, x) - 1);
        else if (op == 4) printf("%d\n", get_key_by_rank(root, x + 1));
        else if (op == 5) printf("%d\n", get_prev(root, x));
        else printf("%d\n", get_next(root, x));
    }
    return 0;
}