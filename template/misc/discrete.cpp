// offline hash c++
vector<int> alls;
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());

// offline hash c
int m, alls[N];
sort(alls, alls + m);
m = unique(alls, alls + m) - alls;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // fenwick tree, index from 1
}

// stl find (slower)
int find(int x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}

// online hash
int n;
unordered_map<int, int> S;

int get(int x) {
    if (S.count(x) == 0) S[x] = ++n;
    return S[x];
}
