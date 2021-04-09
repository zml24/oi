#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 200010;

int n;
int q[N];
int a[N], b[N];

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        scanf("%d", &n);
        set<int> c, d;
        for (int i = 0; i < n; i++) scanf("%d", &q[i]), c.insert(i + 1), d.insert(i + 1);
        a[0] = b[0] = q[0];
        c.erase(q[0]), d.erase(q[0]);
        int mxx = q[0];
        for (int i = 1; i < n; i++) {
            if (q[i] == q[i - 1]) {
                int mi = *c.begin();
                a[i] = mi, c.erase(mi);
                int mx = *(--d.lower_bound(mxx));
                b[i] = mx, d.erase(mx);
            } else {
                a[i] = b[i] = q[i];
                c.erase(q[i]), d.erase(q[i]);
                mxx = q[i];
            }
        }
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        puts("");
        for (int i = 0; i < n; i++) printf("%d ", b[i]);
        puts("");
    }
    return 0;
}