int tt;
int stk[N];

void init() {
    tt = 0;
}

void push(int x) {
    stk[++tt] = x;
}

void pop() {
    tt--;
}

int top() {
    return stk[tt];
}
bool empty() {
    return !tt;
}
