#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int n, m;

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        LL x;
        scanf("%d%d%lld", &n, &m, &x);
        LL a = (x - 1) / n + 1, b = (x - 1) % n + 1;
        LL res = (b - 1) * m + a;
        printf("%lld\n", res);
    }
    return 0;
}