#include <iostream>

void solve(int n) {
  if (n == 0)
    return;
  solve(n - 1);
  std::cout << n << '\n';
}

int main() {
  int n;
  std::cin >> n;

  solve(n);

  return 0;
}
