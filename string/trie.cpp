#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char str[N];
int tr[N][26], cnt[N], idx;

void init() {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    idx = 0;
}

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

int query() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        char op[5];
        scanf("%s%s", op, str);
        if (op[0] == 'I') insert();
        else printf("%d\n", query());
    }
    return 0;
}