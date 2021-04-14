int w[N];
int q[N];

int lis(int n) {
    q[0] = -INF;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = res;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < w[i]) l = mid;
            else r = mid - 1;
        }
        res = max(res, r + 1);
        q[r + 1] = w[i];
    }
    return res;
}
