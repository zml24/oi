#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 110, M = 10010;

int n = 100, m = 10000;
char str[N][M];
int cnt[N];

struct Question {
    int id, cnt;
    bool operator< (const Question& q) const {
        return cnt < q.cnt;
    }
};

struct Player {
    int id, cnt, low, high;
    bool operator< (const Player& p) const {
        return cnt < p.cnt;
    }
};

int main() {
    int TT, p;
    scanf("%d%d", &TT, &p);
    for (int ca = 1; ca <= TT; ca++) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++) scanf("%s", str[i]);
        vector<Question> vq(m);
        for (int i = 0; i < m; i++) vq[i] = {i, 0};
        vector<Player> vp(n);
        for (int i = 0; i < n; i++) vp[i] = {i, 0, 0, 0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (str[i][j] == '1') vp[i].cnt++, vq[j].cnt++;
        sort(vq.begin(), vq.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 20; j++)
                if (str[i][vq[j].id] == '1') vp[i].low++;
            for (int j = 19 * m / 20; j < m; j++)
                if (str[i][vq[j].id] == '1') vp[i].high++;
        }
        sort(vp.begin(), vp.end());
        int avg_low = 0, avg_high = 0;
        for (int i = 0; i < 5; i++) avg_low += vp[i].low, avg_high += vp[i].high;
        for (int i = 0; i < 5; i++) cnt[vp[i].id] += abs(avg_low - vp[i].low * 5) + abs(avg_high - vp[i].high * 5);
        for (int i = 5; i < n; i++) {
            avg_low += vp[i].low, avg_high += vp[i].high;
            avg_low -= vp[i - 5].low, avg_high -= vp[i - 5].high;
            cnt[vp[i].id] += abs(avg_low - vp[i].low * 5) + abs(avg_high - vp[i].high * 5);
        }
        int res = 0;
        for (int i = 1; i < n; i++)
            if (cnt[i] > cnt[res]) res = i;
        printf("Case #%d: %d\n", ca, res + 1);
    }
    return 0;
}