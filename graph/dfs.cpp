void dfs(int u) {
    st[u] = true;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
