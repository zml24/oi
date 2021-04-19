#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
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

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0) return false;
    return true;
}

void solve() {
    LL n;
    scanf("%lld", &n);
    vector<int> primes;
    for (int i = max(2, (int)sqrt(n) - 282 * 2); i <= sqrt(n) + 282; i++)
        if (is_prime(i)) primes.push_back(i);
    for (int i = primes.size() - 1; i; i--)
        if ((LL)primes[i] * primes[i - 1] <= n) {
            printf("%lld\n", (LL)primes[i] * primes[i - 1]);
            break;
        }
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}