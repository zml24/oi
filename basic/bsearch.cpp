int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        // if array a has been sorted from smallest to largest
        // check(mid): a[mid] >= x
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        // if array a has been sorted from smallest to largest
        // check(mid): a[mid] <= x
        else r = mid - 1;
    }
    return l;
}

double bsearch(double l, double r) {
    const double eps = 1e-6;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        // if array a has been sorted from smallest to largest
        // check(mid): a[mid] >= x
        else l = mid;
    }
    return l;
}
