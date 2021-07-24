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

vector<int> read() {
    string str;
    cin >> str;
    vector<int> res;
    size_t idx1 = str.find(","), idx2 = 0;
    while (idx1 != string::npos) {
        res.push_back(stoi(str.substr(idx2, idx1 - idx2)));
        idx2 = idx1 + 1;
        idx1 = str.find(",", idx2);
    }
    res.push_back(stoi(str.substr(idx2, idx1 - idx2)));
    return res;
}
