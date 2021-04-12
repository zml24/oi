#include <bits/stdc++.h>

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

const int N = 15;

char str[N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    scanf("%s", str);
    int n = strlen(str);
    int idx = -1;
    for (int i = n - 1; ~i; i--)
        if (str[i] != '0') {
            idx = i;
            break;
        }
    if (idx == -1) {
        puts("Yes");
        return;
    }
    idx++;
    for (int i = 0; i < idx / 2; i++)
        if (str[i] != str[idx - i - 1]) {
            puts("No");
            return;
        }
    puts("Yes");
}

int main() {
    quick_read();
    solve();
    return 0;
}