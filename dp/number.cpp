int f[N][10];

void init() {
    memset(f, 0, sizeof f);
    for (int i = 0; i <= 9; i++)
        if (i != 8) f[1][i] = 1;
    for (int i = 2; i < n; i++)
        for (int j = 0; j <= 9; j++) {
            if (j == 8) continue;
            for (int k = 0; k <= 9; k++) {
                if (k == 8) continue;
                f[i][j] += f[i - 1][k];
            }
        }
}

int dp(int n) {
    if (!n) return 0;
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    int res = 0, last = 0;
    for (int i = nums.size() - 1; ~i; i--) {
        int x = nums[i];
        for (int j = 0; j < x; j++)
            if (j != 8) res += f[i + 1][j];
        if (x == 8) break;
        last = x;
        if (!i) res++;
    }
    return res;
}

int cal(int l, int r) {
    init();
    return dp(r) - dp(l - 1);
}
