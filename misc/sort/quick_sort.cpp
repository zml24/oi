int n;
int w[N];

void quick_sort(int l, int r) {
    if (l == r) return;
    int x = w[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (w[i] < x);
        do j--; while (w[j] > x);
        if (i < j) swap(w[i], w[j]);
    }
    quick_sort(l, j), quick_sort(j + 1, r);
}
