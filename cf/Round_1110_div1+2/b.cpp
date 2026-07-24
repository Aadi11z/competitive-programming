#include <bits/stdc++.h>
#include <cassert>

using Clock = std::chrono::steady_clock;

template <typename Function>
long long benchmark(Function method, const std::vector<long long> &arr,
                    int iterations, long long cost) {
  long long checksum = 0;
  auto start = Clock::now();

  for (int repeat = 0; repeat < iterations; repeat++) {
    checksum += method(arr, cost);
  }

  auto finish = Clock::now();

  auto elapsed =
      std::chrono::duration_cast<std::chrono::microseconds>(finish - start)
          .count();

  std::cerr << "Checksum: " << checksum << '\n';

  return elapsed;
}

long long method1(std::vector<long long> a, long long c) {
  int n = a.size();

  sort(a.rbegin(), a.rend());

  long long score = 0;
  const int opCount =
      (n + 1) /
      2; // this is because at every step, max 2 elements can be removed,
         // which means that if you have 7 elements, opCount=3 will remove
         // 6 elements and you have one left over, so it will take atleast
         // 4 operations to empty the array. 'EMPTYING THE ARRAY' is key here.
         // So you (n+1)/2 operations at minimum.

  for (int i = 0; i < opCount; i++) {
    score += a[i] - c;
  }

  for (int i = opCount; i < n; i++) {
    score += std::max((long long)0, a[i] - c);
  }

  return score;
}

long long method2(std::vector<long long> a, long long c) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    a[i] -= c; // store cost-adjusted contribution instead of elements
  }

  sort(a.rbegin(), a.rend());

  long long score = 0;
  for (int i = 0; i < n; i++) {
    if (i < (n + 1) / 2 || a[i] > 0) {
      score += a[i];
    }
  }

  return score;
}

int main() {
  constexpr int n = 1000;
  constexpr int iterations = 10000;
  constexpr long long c = 500;

  std::mt19937_64 generator(123456);
  std::uniform_int_distribution<long long> distribution(-1000000000LL,
                                                        1000000000LL);

  std::vector<long long> input(n);

  for (long long &value : input) {
    value = distribution(generator);
  }

  method1(input, c);
  method2(input, c);

  long long time_m1 = benchmark(method1, input, iterations, c);
  long long time_m2 = benchmark(method2, input, iterations, c);

  std::cout << "Method 1: " << time_m1 << " microseconds\n";
  std::cout << "Method 2: " << time_m2 << " microseconds\n";

  assert(method1(input, c) == method2(input, c));

  return 0;
}
