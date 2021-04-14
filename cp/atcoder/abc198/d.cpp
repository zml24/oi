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

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    map<char, int> mp;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (char c : s1) mp[c]++;
    for (char c : s2) mp[c]++;
    for (char c : s3) mp[c]++;
    if (mp.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return;
    }
    vector<int> p(10);
    iota(p.begin(), p.end(), 0);
    do {
        string n1, n2, n3;
        int cnt = 0;
        for (auto& it : mp) it.y = p[cnt++];
        for (char c : s1) n1 += mp[c] + '0';
        for (char c : s2) n2 += mp[c] + '0';
        for (char c : s3) n3 += mp[c] + '0';
        LL a = stoll(n1), b = stoll(n2), c = stoll(n3);
        if (n1[0] != '0' && n2[0] != '0' && n3[0] != '0' && a + b == c) {
            cout << a << endl << b << endl << c << endl;
            return;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << "UNSOLVABLE" << endl;
}

int main() {
    quick_read();
    solve();
    return 0;
}