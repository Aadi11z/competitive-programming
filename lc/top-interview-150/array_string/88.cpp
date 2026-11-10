#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

// Unoptimal solution: append + sort
void merge_unoptimal(vector<int> &nums1, int m, const vector<int> &nums2,
                     int n) {
  for (int i = 0; i < n; i++) {
    nums1[m + i] = nums2[i];
  }
  sort(nums1.begin(), nums1.end());
}

// Optimal solution: two pointers
void merge_optimal(vector<int> &nums1, int m, const vector<int> &nums2, int n) {
  int a = m - 1;
  int b = n - 1;
  int c = m + n - 1;

  while (a >= 0 && b >= 0) {
    if (nums1[a] > nums2[b]) {
      nums1[c--] = nums1[a--];
    } else {
      nums1[c--] = nums2[b--];
    }
  }
  while (b >= 0) {
    nums1[c--] = nums2[b--];
  }
}

void print_vector(const vector<int> &nums) {
  for (int x : nums)
    cout << x << " ";
  cout << '\n';
}

int main() {
  auto start = steady_clock::now();
  vector<int> base_nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;

  const int ITER = 1'000'000; // Fix #1: amplify work

  // -------- Unoptimal timing --------
  auto start1 = steady_clock::now();
  for (int i = 0; i < ITER; i++) {
    vector<int> temp = base_nums1; // reset input
    merge_unoptimal(temp, m, nums2, n);
  }
  auto end1 = steady_clock::now();

  // -------- Optimal timing --------
  auto start2 = steady_clock::now();
  for (int i = 0; i < ITER; i++) {
    vector<int> temp = base_nums1; // reset input
    merge_optimal(temp, m, nums2, n);
  }
  auto end2 = steady_clock::now();

  // Print once (excluded from timing)
  vector<int> nums1_unoptimal = base_nums1;
  vector<int> nums1_optimal = base_nums1;

  merge_unoptimal(nums1_unoptimal, m, nums2, n);
  merge_optimal(nums1_optimal, m, nums2, n);

  print_vector(nums1_unoptimal);
  print_vector(nums1_optimal);

  cout << "Unoptimal avg time: "
       << duration_cast<nanoseconds>(end1 - start1).count() / ITER << " ns\n";

  cout << "Optimal avg time:   "
       << duration_cast<nanoseconds>(end2 - start2).count() / ITER << " ns\n";

  auto end = steady_clock::now();
  cout << "Total time: "
       << duration_cast<nanoseconds>(end - start).count() / ITER << " ns\n";

  return 0;
}
