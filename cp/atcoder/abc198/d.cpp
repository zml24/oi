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
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

const int N = 15;

char str1[N], str2[N], str3[N];
char mp[30];
int cnt = 0;
double w[N][N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    mp.clear();
    memset(mp, 0, sizeof mp);
    cnt = 0;
    scanf("%s%s%s", str1, str2, str3);
    int m1 = strlen(str1), m2 = strlen(str2), m3 = strlen(str3);
    for (int i = 0; i < m1; i++)
        if (!mp[str1[i] - 'a']) mp[str1[i] - 'a'] = ++cnt;
    for (int i = 0; i < m2; i++)
        if (!mp[str2[i] - 'a']) mp[str2[i] - 'a'] = ++cnt;
    for (int i = 0; i < m3; i++)
        if (!mp[str3[i] - 'a']) mp[str3[i] - 'a'] = ++cnt;
    for (int i = 0; i < max(m1, max(m2, m3)); i++) {
        if (m1 >= i && m2 >= i && m3 >= i) {
            for (int j = 0; j < 3; j++) a[i][]
        }
    }
        for (int j = 0; j < cnt; j++)

}

int main() {
    quick_read();
    solve();
    return 0;
}