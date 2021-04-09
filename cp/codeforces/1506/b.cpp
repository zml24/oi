#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 60;

int n, k;
char str[N];

void solve() {
    scanf("%d%d%s", &n, &k, str);
    int res = 1;
    int idx = -1;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '*') {
            idx = i;
            break;
        }
    while (true) {
        int j = min(n - 1, idx + k);
        while (idx < j && str[j] == '.') j--;
        if (idx == j) break;
        res++;
        idx = j;
    }
    printf("%d\n", res);
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}