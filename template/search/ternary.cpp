int search(int l, int r) {
    while (l < r) {
        if (l + 1 == r) {
            if (l) l--;
            else r++;
        }
        int ml = l + l + r >> 1, mr = l + r + r >> 1;
    }
    while (l + 1 < r) {
        int ml = l + r >> 1;
        int mr = ml + r >> 1;
        if (get(ml) > get(mr)) l = ml;
        // find minimal
        else r = mr;
    }
    return min(cal(l), cal(r));
}
