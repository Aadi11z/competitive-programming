#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        long long c;
        std::cin >> n >> c;

        std::vector<long long> a(n);
        for (long long& value : a) {
            std::cin >> value;
        }

        sort(a.rbegin(), a.rend());

        long long score = 0;
        const int opCount = (n + 1) / 2;

        for (int i = 0; i < opCount; i++) {
            score += a[i] - c;
        }

        for (int i = opCount; i < n; i++) {
            score += std::max((long long) 0, a[i] - c);
        }

        std::cout << score << std::endl;
    }

    return 0;
}
