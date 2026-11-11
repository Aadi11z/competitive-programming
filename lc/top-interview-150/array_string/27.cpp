#include <bits/stdc++.h>

int removeElement(std::vector<int> &nums, int val) {
  nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
  nums.shrink_to_fit();

  return nums.size();
}

int main() {
  std::vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int ans = removeElement(nums, val);

  std::cout << ans << '\n';

  for (int x : nums)
    std::cout << x;

  return 0;
}
