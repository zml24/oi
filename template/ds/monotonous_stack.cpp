int stk[N];
int tt = 0;
for (int i = 1; i <= n; i++) {
    while (tt && check(stk[tt], i)) tt--;
    // to find the fisrt number on the left that is smaller than a[i]
    // check(stk[tt], i): a[stk[tt]] >= a[i]
    // else
    // check(stk[tt], i): a[stk[tt]] <= a[i]
    stk[++tt] = i;
}
