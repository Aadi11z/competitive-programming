#include <bits/stdc++.h>

int removeDuplicates(std::vector<int>& nums) {
    int k = 2;
    if (nums.size() <= 2) return nums.size();

    for (int i = 2; i < (int)nums.size(); i++) {
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int ans = removeDuplicates(nums);
    std::cout << ans << '\n';

    for (int i = 0; i < ans; i++) {
        std::cout << nums[i] << " ";
    }

    return 0;
}
