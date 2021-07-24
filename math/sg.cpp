int sg(int x) {
    if (!f[x]) return f[x];
    unordered_set<int> S;
    for (int i = 0; i < x; i++)
        S.insert(sg(i));
    for (int i = 0; ; i++)
        if (!S.count(i)) return f[x] = i;
}

bool cal() {
    int res;
    for (int i = 0; i < n; i++) res ^= sg(w[i]);
    return res;
}
