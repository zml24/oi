int n;
int w[N], tmp[N];

void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (w[i] <= w[j]) tmp[k++] = w[i++];
        else tmp[k++] = w[j++];
    }
    while (i <= mid) tmp[k++] = w[i++];
    while (j <= r) tmp[k++] = w[j++];
    for (int i = l, j = 0; i <= r; i++, j++) w[i] = tmp[j];
}

