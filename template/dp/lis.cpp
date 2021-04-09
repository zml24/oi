// dynamic programming in O(n^2)
for (int i = 0; i < n; i++) f[i] = 1;
for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
        if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
int res = 0;
for (int i = 0; i < n; i++) res = max(res, f[i]);

// greedy in O(nlogn)
q[0] = -INF;
int res = 0;
for (int i = 0; i < n; i++) {
    int l = 0, r = res;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (q[mid] < a[i]) l = mid;
        else r = mid - 1;
    }
    res = max(res, r + 1);
    q[r + 1] = a[i];
}
