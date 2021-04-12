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

const int N = 110;

int n;
string str[N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool check9(int a, int b) {
    for (int i = str[a].size(); i < str[b].size(); i++)
        if (str[b][i] != '9') return false;
    return true;
}

int check(int a, int b) {
    for (int i = 0; i < str[a].size(); i++) {
        if (str[a][i] < str[b][i]) return -1;
        if (str[a][i] > str[b][i]) return 1;
    }
    return 0;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> str[i];
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (str[i - 1].size() < str[i].size()) continue;
        else if (str[i - 1].size() == str[i].size()) {
            if (check(i, i - 1) <= 0) res++, str[i] += '0';
        } else {
            if (check(i, i - 1) == 1) {
                res += str[i - 1].size() - str[i].size();
                for (int j = str[i].size(); j < str[i - 1].size(); j++) str[i] += '0';
            } else if (check(i, i - 1) == 0 && !check9(i, i - 1)) {
                int t = str[i].size();
                res += str[i - 1].size() - str[i].size();
                for (int j = str[i].size(); j < str[i - 1].size(); j++) str[i] += str[i - 1][j];
                int idx = 0;
                for (int j = str[i].size() - 1; j >= t; j--)
                    if (str[i][j] != '9') {
                        str[i][j] = str[i - 1][j] + 1;
                        idx = j;
                        break;
                    }
                for (int j = idx + 1; j < str[i].size(); j++) str[i][j] = '0';
            } else {
                res += str[i - 1].size() - str[i].size() + 1;
                for (int j = str[i].size(); j <= str[i - 1].size(); j++) str[i] += '0';
            }
        }
    }
    cout << res << endl;
}

int main() {
    quick_read();
    int TT;
    cin >> TT;
    for (int ca = 1; ca <= TT; ca++) {
        cout << "Case #" << ca << ": ";
        solve();
    }
    return 0;
}