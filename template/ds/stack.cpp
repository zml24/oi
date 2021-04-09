int tt = 0;
int stk[N];

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
