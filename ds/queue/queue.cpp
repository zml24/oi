int hh, tt; 
int q[N];

void init() {
    hh = 0, tt = -1;
}

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
