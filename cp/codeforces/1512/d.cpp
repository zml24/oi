#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

const int N = 200010;

int n;
LL b[N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int find(LL x, int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() {
    memset(b, 0, sizeof b);
    scanf("%d", &n);
    for (int i = 0; i < n + 2; i++) scanf("%d", &b[i]);
    sort(b, b + n + 2);
    LL sum = 0;
    for (int i = 0; i < n + 1; i++) sum += b[i];
    if (sum <= b[n]) puts("-1");
    else {
        int idx = find(sum - b[n + 1], 0, n);
        if (b[idx] == sum - b[n + 1]) {
            for (int i = 0; i <= n; i++)
                if (i != idx) printf("%d ", b[i]);
            puts("");
        } else if (sum - b[n] == b[n]) {
            for (int i = 0; i < n; i++) printf("%d ", b[i]);
            puts("");
        }
        else puts("-1");
    }
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}