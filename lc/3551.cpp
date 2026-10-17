#include "bits/stdc++.h"
using namespace std;

int minSwaps(vector<int> &nums) {
  auto digit_sum = [](int x) {
    int sum = 0;
    for (; x > 0; x /= 10)
      sum += x % 10;
    return sum;
  };
  int n = nums.size();

  // Create and {sum: val} pair, sort based on sum then val
  vector<pair<int, int>> paired;
  for (auto x : nums)
    paired.emplace_back(digit_sum(x), x);
  sort(paired.begin(), paired.end());

  // Note position for every val
  unordered_map<int, int> mapped;
  for (int k = 0; k < n; k++)
    mapped[paired[k].second] = k;

  //
  vector<int> placed;
  for (int x : nums)
    placed.push_back(mapped[x]);

  int count = 0;

  for (int i = 0; i < n; i++) {
    while (placed[i] != i) {
      int j = placed[i];
      swap(placed[i], placed[j]);
      count++;
    }
  }
  return count;
}

int main() {
  vector<int> nums = {18, 43, 34, 16};
  int ans = minSwaps(nums);
  cout << ans << '\n';

  return 0;
}
