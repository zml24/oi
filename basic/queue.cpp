// queue, hh for the front and tt for the back
int q[N], hh = 0, tt = -1; 

void push(int x) {
    q[++tt] = x;
}

void pop() {
    hh++;
}

int front() {
    return q[hh];
}

bool empty() {
    return hh > tt;
}

// circular queue, hh for the head and tt - 1 for the back
int q[N], hh = 0, tt = 0;

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
