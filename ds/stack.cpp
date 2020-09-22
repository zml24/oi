# stack
int stk[N], tt = 0;

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
    return tt;
}

# monotone stack
int tt = 0;
for (int i = 1; i <= n; i++) {
    while (tt && check(stk[tt], i)) tt--;
    stk[++tt] = i;
}
