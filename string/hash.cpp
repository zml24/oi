#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010;
const int P = 131;

int n;
char str[N]; // 1-index
ULL h[N], p[N];

void init() {
    n = strlen(str + 1), p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
}

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    scanf("%s", str + 1);
    init();
    return 0;
}