#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int w[N], alls[N];

void init() {
    m = 0;
}

int find(int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        alls[m++] = w[i];
    }
    sort(alls, alls + m);
    m = unique(alls, alls + m) - alls;
    for (int i = 0; i < n; i++) printf("%d\n", find(w[i]));
    return 0;
}