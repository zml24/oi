#include <bits/stdc++.h>

using namespace std;

const int N = 20000010;

int n;
char a[N], b[N];
int p[N];

void init() {
    n = strlen(a);
    int k = 0;
    b[k++] = '$', b[k++] = '#';
    for (int i = 0; i < n; i++) b[k++] = a[i], b[k++] = '#';
    b[k++] = '^';
    n = k;
}

int manacher() {
    int mr = 0, mid, res = 0;
    for (int i = 1; i < n; i++) {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;
        while (b[i - p[i]] == b[i + p[i]]) p[i]++;
        res = max(res, p[i] - 1);
        if (mr < i + p[i]) {
            mr = i + p[i];
            mid = i;
        }
    }
    return res;
}

int main() {
    scanf("%s", a);
    init();
    printf("%d\n", manacher());
    return 0;
}
