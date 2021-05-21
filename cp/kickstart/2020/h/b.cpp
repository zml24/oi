#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

const int N = 20;

LL l, r;
LL f[N];
int a[10] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};
int b[10] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5};

void init() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * 5;
}

LL dp(LL n) {
    if (!n) return 0;
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    LL res = 0;
    for (int i = 1; i < nums.size(); i++) res += f[i];
    for (int i = nums.size() - 1; ~i; i--) {
        int x = nums[i];
        int k = nums.size() - i;
        if ((k ^ x) & 1) {
            res += b[x] * f[i];
            break;
        } else {
            res += a[x] * f[i];
            if (!i) res++;
        }
    }
    return res;
}

void solve() {
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", dp(r) - dp(l - 1));
}

int main() {
    init();
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}