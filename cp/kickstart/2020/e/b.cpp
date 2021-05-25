#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
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
    cout.precision(20);
    cout.tie(nullptr);
    return 0;
}();

bool solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int m = n - (a + b - c);
    if (m < 0) return false;
    if (n == 1) {
        if (a == 1 && b == 1 && c == 1) cout << 1 << endl;
        else return false;
    } else if (n == 2) {
        if (a == 2 && b == 1 && c == 1) cout << 1 << " " << 2 << endl;
        else if (a == 2 && b == 2 && c == 2) cout << 2 << " " << 2 << endl;
        else if (a == 1 && b == 2 && c == 1) cout << 2 << " " << 1 << endl;
        else return false; 
    } else {
        int l = a - c, mid = c, r = b - c;
        if (l + mid + r <= 1 && m != 0) return false;
        int flag = 0;
        if (l > 0) flag = 1;
        if (mid > 1) flag = 2;
        while (l--) cout << n - 1 << " ";
        if (flag == 1)
            while (m--) cout << n - 2 << " ";
        if (flag == 2) {
            cout << n << " ";
            mid--;
            while (m--) cout << n - 2 << " ";
        }
        while (mid--) cout << n << " ";
        if (!flag)
            while (m--) cout << n - 2 << " ";
        while (r--) cout << n - 1 << " ";
        cout << endl;
    }
    return true;
}

int main() {
    int TT;
    cin >> TT;
    for (int ca = 1; ca <= TT; ca++) {
        cout << "Case #" << ca << ": ";
        if (!solve()) cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}