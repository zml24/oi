void init() {
    int k = 0;
    b[k++] = '$', b[k++] = '#';
    for (int i = 0; i < n; i++) b[k++] = a[i], b[k++] = '#';
    b[k++] = '^';
    n = k;
}

int manacher() {
    int res = 0;
    int mr = 0, mid;
    for (int i = 1; i < n; i++) {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;
        while (b[i - p[i]] == b[i + p[i]]) p[i]++;
        if (i + p[i] > mr) {
            mr = i + p[i];
            mid = i;
        }
        res = max(res, p[i] - 1);
    }
    return res;
}
