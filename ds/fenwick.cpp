#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int w[N], tr[N]; // 1-index

int lowbit(int x) {
    return x & -x;
}

void init() {
    memset(tr, 0, sizeof tr);
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x) {
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) add(i, w[i] - w[i - 1]);
    while (m--) {
        char op[2];
        int l;
        scanf("%s%d", op, &l);
        if (*op == 'C') {
            int r, d;
            scanf("%d%d", &r, &d);
            add(l, d), add(r + 1, -d);
        } else printf("%lld\n", sum(l));
    }
    return 0;
}

// 全1初始化
// void init() {
//     for (int i = 1; i <= n; i++) tr[i] = lowbit(i);
// }

// O(n)建树
// void init() {
//     memset(tr, 0, sizeof tr);
//     for (int i = 1; i <= n; i++) {
//         tr[i] += w[i];
//         int j = i + lowbit(i);
//         if (j <= n) tr[j] += tr[i];
//     }
// }

// 区间修改，区间查询
// void range_add(int l, int r, int d) {
//     add(tr1, l, d), add(tr1, r + 1, -d);
//     add(tr2, l, l * d), add(tr2, r + 1, (r + 1) * -d);
// }

// int range_sum(int l, int r) {
//     return sum(tr1, r) * (r + 1) - sum(tr2, r) - sum(tr1, l - 1) * l + sum(tr2, l - 1);
// }
