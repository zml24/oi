int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

bool solve(int a, int b, int c, int &z) {
    int x, y;
    int d = exgcd(a, -c, x, y);
    if (b % d) return false;
    z = (LL)b / d * x % c;
    return true;
}
