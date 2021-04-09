int hh = 0, tt = 0;
int q[N];

void push(int x) {
    q[tt++] = x;
    if (tt == N) tt = 0;
}

void pop() {
    hh++;
    if (hh == N) hh = 0;
}

int front() {
    return q[hh];
}

bool empty() {
    return hh == tt;
}
