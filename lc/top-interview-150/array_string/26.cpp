#include <bits/stdc++.h>

int removeDuplicates(std::vector<int> &nums) {
  int a = 0;
  int b = 1;
  while (b < (int)nums.size()) {
    if (nums[a] == nums[b]) {
      nums.erase(nums.begin() + b);
    } else {
      b++;
      a++;
    }
  }

  return nums.size();
}

int main() {
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int res = removeDuplicates(nums);

  std::cout << res << '\n';

  for (int x : nums)
    std::cout << x << " ";

  return 0;
}
