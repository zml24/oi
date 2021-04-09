int hh = 0, tt = -1; 
int q[N];

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
