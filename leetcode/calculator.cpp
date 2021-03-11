int t1, t2;
LL num[N];
char op[N];
unordered_map<char, int> pr;

void eval() {
    LL b = num[t1--], a = num[t1--];
    char c = op[t2--];
    t1 = max(t1, 0);
    LL res;
    if (c == '+') res = a + b;
    else if (c == '-') res = a - b;
    else if (c == '*') res = a * b;
    else res = a / b;
    num[++t1] = res;
}

int calculate(string s) {
    t1 = t2 = 0;
    pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        auto c = s[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            LL x = 0;
            int j = i;
            while (j < n && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
            num[++t1] = x;
            i = j - 1;
        } else if (c == '(') op[++t2] = c;
        else if (c == ')') {
            while (op[t2] != '(') eval();
            t2--;
        } else {
            while (t2 && op[t2] != '(' && pr[op[t2]] >= pr[c]) eval();
            op[++t2] = c;
        }
    }
    while (t2) eval();
    return num[t1];
}
