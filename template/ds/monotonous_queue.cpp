int q[N];
int hh = 0, tt = -1;
for (int i = 0; i < n; i++) {
    while (hh <= tt && check_out(q[hh])) hh++;
    while (hh <= tt && check(q[tt], i)) tt--;
    // to find the minimum value in the sliding window in the array a
    // check(q[tt], i): a[q[tt]] >= a[i]
    // else
    // check(q[tt], i): a[q[tt]] <= a[i]
    q[++tt] = i;
}
