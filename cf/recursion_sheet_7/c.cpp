#include <iostream>

void solve(int n) {
  if (n == 1) {
    std::cout << n;
    return;
  }
  std::cout << n-- << ' ';
  solve(n);
}

int main() {
  int n;
  std::cin >> n;

  solve(n);

  return 0;
}
