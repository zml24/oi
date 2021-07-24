vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ ) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> mul(string a, int b) {
    vector<int> A;
    for (int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
    return mul(A, b);
}

void print(string a, int b) {
    auto C = mul(a, b);
    for (int i = C.size() - 1; ~i; i--) cout << C[i];
    cout << endl;
}