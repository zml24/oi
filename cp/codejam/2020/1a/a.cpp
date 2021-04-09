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

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 60, M = 110;

int n;
string str;
vector<string> pres, ins, posts;
string res;

void solve() {
    pres.clear();
    ins.clear();
    posts.clear();
    res = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        int l = -1, r = -1;
        bool isPre = false, isPost = false;
        for (int j = 0; j < str.size(); j++)
            if (str[j] == '*') {
                if (l == -1) l = j;
                else r = j;
                if (j == 0) isPost = true;
                else if (j == str.size() - 1) isPre = true;
            }
        if (r == -1 && isPre) pres.push_back(str.substr(0, str.size() - 1));
        else if (r == -1 && isPost) posts.push_back(str.substr(1, str.size() - 1));
        else if (l == -1) pres.push_back(str), posts.push_back(str);
        else if (r == -1) pres.push_back(str.substr(0, l)), posts.push_back(str.substr(l + 1));
        else {
            pres.push_back(str.substr(0, l));
            ins.push_back(str.substr(l + 1, r - l - 1));
            posts.push_back(str.substr(r + 1));
        }
    }
    if (pres.size()) {
        int idx = 0;
        for (int i = 1; i < pres.size(); i++)
            if (pres[i].size() > pres[idx].size()) idx = i;
        for (int i = 0; i < pres.size(); i++)
            for (int j = 0; j < pres[i].size(); j++)
                if (pres[idx][j] != pres[i][j]) {
                    cout << "*" << endl;
                    return;
                }
        res += pres[idx];
    }
    if (ins.size()) {
        for (int i = 0; i < ins.size(); i++)
            for (int j = 0; j < ins[i].size(); j++)
                if (ins[i][j] != '*') res += ins[i][j];
    }
    if (posts.size()) {
        int idx = 0;
        for (int i = 1; i < posts.size(); i++)
            if (posts[i].size() > posts[idx].size()) idx = i;
        for (int i = 0; i < posts.size(); i++)
            for (int j = 0; j < posts[i].size(); j++)
                if (posts[idx][posts[idx].size() - 1 - j] != posts[i][posts[i].size() - 1 - j]) {
                    cout << "*" << endl;
                    return;
                }
        res += posts[idx];
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