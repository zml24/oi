#include <bits/stdc++.h>

using namespace std;



char str[N];
int tr[N][26], cnt[N], idx;
int q[N], ne[N];

void init() {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    memset(ne, 0, sizeof ne);
    idx = 0;
}

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int t = str[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++idx;
        p = tr[p][t];
    }
    cnt[p]++;
}

void build() {
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i++)
        if (tr[0][i]) q[++tt] = tr[0][i];
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = 0; i < 26; i++) {
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[ne[t]][i];
            else {
                ne[p] = tr[ne[t]][i];
                q[++tt] = p;
            }
        }
    }
}

int query() {
    int res = 0;
    for (int i = 0, j = 0; str[i]; i++) {
        int u = str[i] - 'a';
        j = tr[j][u];
        int p = j;
        while (p) {
            res += cnt[p];
            cnt[p] = 0;
            p = ne[p];
        }
    }
    return res;
}
