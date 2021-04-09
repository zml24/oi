#pragma GCC optimize(2)

#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int n;

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        scanf("%d", &n);
        int x;
        unordered_map<int, int> S;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            S[x]++;
        }
        priority_queue<PII> pq;
        for (auto it : S) pq.push({it.y, it.x});
        int res = n;
        while (pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            if (a.x > 1) pq.push({a.x - 1, a.y});
            if (b.x > 1) pq.push({b.x - 1, b.y});
            res -= 2;
        }
        printf("%d\n", res);
    }
    return 0;
}