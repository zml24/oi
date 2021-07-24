vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; ~i; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> div(string a, int b, int &r) {
    vector<int> A;
    for (int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
    return div(A, b, r);
}

void print(string a, int b) {
    int r;
    auto C = div(a, b, r);
    for (int i = C.size() - 1; ~i; i--) cout << C[i];
    cout << endl << r << endl;
}