// append to itself
int n = a.size();
a.resize(2 * n);
copy_n(a.begin(), n, a,begin() + n);
