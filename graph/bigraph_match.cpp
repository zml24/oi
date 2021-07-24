int n, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int matching() {
    memset(match, 0, sizeof match);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(st, 0, sizeof st);
        if (find(i)) res++;
    }
    return res;
}
