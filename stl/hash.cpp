void array() {
    static constexpr auto arrayHash = [fn = hash<int>()](const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp{0, arrayHash};
}

void pair() {
    static constexpr auto pairHash = [fn = hash<int>()](const pair<int, int>& u) {
        return (fn(u.first) << 16) ^ fn(u.second);
    };
    unordered_map<pair<int, int>, int, decltype(pairHash)> mp{0, pairHash};
}

