const int N = 200003;
const int null = 0x3f3f3f3f;

int h[N];

void init() {
    memset(h, null, sizeof h);
}

void insert(int x) {
    h[get(x)] = x;
}

int get(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) t = 0;
    }
    return t;
}

bool find(int x) {
    return h[get(x)] != null;
}
