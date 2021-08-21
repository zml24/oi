#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int w[N];
unordered_map<int, int> S;

void init() {
    m = 0;
    S.clear();
}

int get(int x) {
    if (!S.count(x)) S[x] = ++m;
    return S[x];
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        printf("%d\n", get(w[i]));
    }
    return 0;
}