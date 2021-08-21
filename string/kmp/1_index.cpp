#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, M = 100010;

int n, m;
char s[N], p[M]; // 1-index
int ne[M];

void init() {
    n = strlen(s + 1), m = strlen(p + 1);
    for (int i = 2, j = ne[1] = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
}

void query() {
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
            printf("%d ", i - j);
            j = ne[j];
        }
    }
}

int main() {
    scanf("%s%s", s + 1, p + 1);
    init();
    query();
    return 0;
}