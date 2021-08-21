#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, M = 100010;

int n, m;
char s[N], p[M]; // 0-index
int ne[M];

void init() {
    n = strlen(s), m = strlen(p);
    for (int i = 1, j = ne[0] = -1; i < m; i++) {
        while (~j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
}

void query() {
    for (int i = 0, j = -1; i < n; i++) {
        while (~j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m - 1) {
            printf("%d ", i - j);
            j = ne[j];
        }
    }
}

int main() {
    scanf("%s%s", s, p);
    init();
    query();
    return 0;
}