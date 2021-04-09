int read() {
    int res = 0;
    char op = getchar();
    while (op < '0' || op > '9') op = getchar();
    while (op >= '0' && op <= '9') {
        res = res * 10 + op - '0';
        op = getchar();
    }
    return res;
}
