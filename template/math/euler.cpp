// n = p1^q1 * p2^q1 * ... * pk^qk
// phi(n) = n * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / pk)

int phi(int n) {
    int res = n;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) res = res / n * (n - 1);
    return res;
}
