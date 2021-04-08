map<int, int> mp;

void divide(int n) {
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            mp[i] += s;
        }
    if (n > 1) mp[n]++;
}
