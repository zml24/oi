char s[N];
char s_new[2 * N];

int init() {
    int j = 0, len = strlen(s);
    s_new[j++] = '$';
    s_new[j++] = '#';

    for (int i = 0; i < len; i++) {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }

    s_new[j++] = '^';
    s_new[j++] = '\0';

    return j;
}

int manacher() {
    int len = init();
    int max_len = -1;

    int id;
    int mx = 0;

    for (int i = 1; i < len; i++) {
        if (i < mx) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while (s_new[i - p[i]] == s_new[i + p[i]]) p[i]++;
        if (mx < i + p[i]) {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }
    
    return max_len;
}
