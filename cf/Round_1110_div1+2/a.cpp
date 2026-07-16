#include<bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, k;
        std::string s;
        std::cin >> n >> k;
        std::cin >> s;
        int count = 0;

        if (2 * k > n) {
            std::cout << -1 << std::endl;
            continue;
        }

        for (int i = 0; i < k; i++) {
            if (s[i] == 'L') {
                count++;
            }
        }

        for (int i = n - 1; i > n - k - 1; i--) {
            if (s[i] == 'R') {
                count++;
            }
        }

        std::cout << count << std::endl;
    }
    return 0;
}