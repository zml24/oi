int primes[N], cnt;
int sum[N];
bool st[N];

void get_primes(int n) {
    if (n < 2) return;
    primes[cnt++] = 2;
    for (int i = 3; i <= n / i; i += 2)
        if (!st[i])
            for (int j = i; j <= n / i; j += 2) st[i * j] = true;
    for (int i = 3; i <= n; i += 2)
        if (!st[i]) primes[cnt++] = i;
}

int get(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> get(int a, int b) {
    get_primes(a);
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]);
    return res;
}
