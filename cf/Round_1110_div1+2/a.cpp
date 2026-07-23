#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, k;
    std::string s;
    std::cin >> n >> k;
    std::cin >> s;
    int count = 0;

    for (int i = 0; i < k; i++) {
      count += (s[i] == 'L');
      count += (s[n - 1 - i] == 'R');
    }

    std::cout << count << std::endl;
  }
  return 0;
}
