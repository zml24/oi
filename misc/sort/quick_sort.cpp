#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int w[N];

void quick_sort(int l, int r) {
    if (l == r) return;
    int x = w[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (w[i] < x);
        do j--; while (w[j] > x);
        if (i < j) swap(w[i], w[j]);
    }
    quick_sort(l, j), quick_sort(j + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", w[i]);
    return 0;
}