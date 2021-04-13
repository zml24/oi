#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e7 + 100;

long long s[N];
int d[N];
int ans[N];

int main() {
    fill(d, d + N, -1);
    d[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (d[i] == -1) {
            d[i] = i;
            for (int j = i * i; j < N; j += i) {
                if (d[j] == -1) {
                    d[j] = i;
                }
            }
        }
    }
    s[1] = 1;
    for (int i = 2; i < N; i++) {
        if (d[i] == -1) {
            d[i] = i;
            s[i] = i + 1;
        } else {
            int j = i;
            s[i] = 1;
            while (j % d[i] == 0) {
                j /= d[i];
                s[i] = s[i] * d[i] + 1;
            }
            s[i] *= s[j];
        }
    }
    fill(ans, ans + N, -1);
    for (int i = N - 1; i > 0; i--) {
        if (s[i] < N) {
            ans[s[i]] = i;
        }
    }
    int tests;
    cin >> tests;
    while (tests-- > 0) {
        int c;
        cin >> c;
        cout << ans[c] << endl;
    }
    return 0;
}