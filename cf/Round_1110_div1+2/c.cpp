#include <bits/stdc++.h>

int rangeXOR(int x) {
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    if (x % 4 == 0) return x;
    return 0;
}

bool permute(int n, long long k, std::vector<int>& p) {
    p.resize(n);
    std::iota(p.begin(), p.end(), 0);

    long long a = rangeXOR(n);
    long long b = a ^ k;

    int x = -1;
    int y = -1;

    for (int i = 0; i < n; i++) {
        long long c = i ^ b;

        if (c < n) {
            x = i;
            y = static_cast<int>(c);
            break;
        }
    }

    if (x == -1) {
        return false;
    }

    if (x != y) {
        int l = std::min(x, y);
        int r = std::max(x, y);

        std::rotate(
            p.begin() + l,
            p.begin() + r,
            p.begin() + r + 1
        );
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;

        std::vector<int> p;

        if (permute(n, k, p)) {
            std::cout << "YES\n";

            for (int i = 0; i < n; i++) {
                std::cout << p[i] << " \n"[i == n - 1];
            }
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
