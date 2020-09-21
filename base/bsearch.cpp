int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

double bsearch(double l, double r) {
    const double eps = 1e-6;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid;
    }
    return l;
}
