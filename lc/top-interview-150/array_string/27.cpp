#include <bits/stdc++.h>

int removeElement(std::vector<int> &nums, int val) {
  int k = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (nums[i] != val) {
      nums[k++] = nums[i];
    }
  }
  return k;
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
