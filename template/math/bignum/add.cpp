vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

vector<int> add(string a, string b) {
    vector<int> A, B;
    for (int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
    return add(A, B);
}

void print(string a, string b) {
    auto C = add(a, b);
    for (int i = C.size() - 1; ~i; i--) cout << C[i];
    cout << endl;
}