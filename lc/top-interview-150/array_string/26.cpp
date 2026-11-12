#include <bits/stdc++.h>

int removeDuplicates(std::vector<int> &nums) {
  int a = 0;

  for (int i = 1; i < (int)nums.size(); i++) {
    if (nums[i] != nums[a]) {
      a++;
      nums[a] = nums[i];
    }
  }

  return a + 1;
}

int main() {
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int res = removeDuplicates(nums);

  std::cout << res << '\n';

  for (int i = 0; i < res; i++)
    std::cout << nums[i] << " ";

  return 0;
}
