#include <iostream>
#include <string>

void solve(int n, std::string ans) {
  int rem = n % 2;
  int res = n / 2;
  ans = ans + std::to_string(rem);
  if (res == 0) {
    ans = std::string(ans.rbegin(), ans.rend());
    std::cout << ans << '\n';
    return;
  }
  solve(res, ans);
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;

    std::string ans = "";
    solve(n, ans);
  }

  return 0;
}
