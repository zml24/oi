#include <bits/stdc++.h>

using namespace std;

int extend(queue<int> &q, unordered_map<int, int> &da, unordered_map<int, int> &db) {
    int mx = sz(q);
    for (int k = 0; k < mx; k++) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int u = t + dx[i];
            if (db.count(u)) return da[t] + 1 + db[u];
            if (da.count(u)) continue;
            da[u] = da[t] + 1;
            q.push(u);
        }
    }
    return -1;
}

int bfs() {
    queue<int> qa, qb;
    unordered_map<int, int> da, db;
    qa.push(S), da[S] = 0;
    qb.push(T), db[T] = 0;
    while (sz(qa) && sz(qb)) {
        int res;
        if (sz(qa) <= sz(qb)) res = extend(qa, da, db);
        else res = extend(qb, db, da);
        if (~res) return res;
    }
    return -1;
}

int main() {
    return 0;
}