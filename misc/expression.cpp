int tt1, tt2;
LL num[N];
char op[N];
unordered_map<char, int> pr;

void eval() {
    LL b = num[tt1--], a = num[tt1--];
    char c = op[tt2--];
    tt1 = max(tt1, 0);
    LL res;
    if (c == '+') res = a + b;
    else if (c == '-') res = a - b;
    else if (c == '*') res = a * b;
    else res = a / b;
    num[++tt1] = res;
}

int calculate(char* str) {
    tt1 = tt2 = 0;
    pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        auto c = s[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            LL x = 0;
            int j = i;
            while (j < n && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
            num[++tt1] = x;
            i = j - 1;
        } else if (c == '(') op[++tt2] = c;
        else if (c == ')') {
            while (op[tt2] != '(') eval();
            tt2--;
        } else {
            while (tt2 && op[tt2] != '(' && pr[op[tt2]] >= pr[c]) eval();
            op[++tt2] = c;
        }
    }
    while (tt2) eval();
    return num[tt1];
}
