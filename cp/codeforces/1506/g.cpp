#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 200010, M = 30;

char str[N];
int cnt[M], stk[M];
bool st[M];

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        memset(cnt, 0, sizeof cnt);
        memset(st, 0, sizeof st);
        scanf("%s", str);
        int n = strlen(str);
        for (int i = 0; i < n; i++) cnt[str[i] - 'a']++;
        int tt = 0;
        for (int i = 0; i < n; i++) {
            if (!st[str[i] - 'a']) {
                while (tt && str[stk[tt]] < str[i]) {
                    if (cnt[str[stk[tt]] - 'a']) {
                        st[str[stk[tt]] - 'a'] = false;
                        tt--;
                    } else break;
                }
                st[str[i] - 'a'] = true;
                stk[++tt] = i;
            }
            cnt[str[i] - 'a']--;
        }
        for (int i = 1; i <= tt; i++) printf("%c", str[stk[i]]);
        puts("");
    }
    return 0;
}