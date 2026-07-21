// String processing consisting of 3 symbols: A, B, C
// String S - length N.
// Only adjacent symbols are allowed to be swapped according to the following
// operations: AB -> BA BC -> CB Task: Find maximum number of operations that
// can be performed on the string (always finite)

#include <bits/stdc++.h>
using namespace std;

long long maxOperations(const string &s) {
  const int n = static_cast<int>(s.size());

  vector<int> leftA(n, 0);
  vector<int> rightC(n, 0);

  int countA = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      ++countA;
    } else if (s[i] == 'C') {
      countA = 0;
    } else {
      leftA[i] = countA;
    }
  }

  int countC = 0;

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'C') {
      ++countC;
    } else if (s[i] == 'A') {
      countC = 0;
    } else {
      rightC[i] = countC;
    }
  }

  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      ans += max(leftA[i], rightC[i]);
    }
  }

  return ans;
}

int main() {
  int n;
  string s;

  cin >> n >> s;
  cout << maxOperations(s) << '\n';

  return 0;
}
