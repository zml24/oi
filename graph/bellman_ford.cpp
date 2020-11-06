int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    else return dist[n];
}
