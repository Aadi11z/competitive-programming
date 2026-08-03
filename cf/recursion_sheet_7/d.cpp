#include <iostream>

void solve(int n) {
  if (n >= 10) {
    solve(n / 10);
  }
  std::cout << n % 10 << ' ';
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;

    solve(n);
    std::cout << '\n';
  }

  return 0;
}
