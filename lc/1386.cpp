#include <iostream>
#include <unordered_map>
#include <vector>

int maxNumberOfFamilies(int n, std::vector<std::vector<int>> &reservedSeats) {
  std::unordered_map<int, int> rows;

  for (auto &seat : reservedSeats) {
    int row = seat[0];
    int col = seat[1];

    if (col >= 2 && col <= 9) {
      rows[row] |= 1 << col;
    }
  }

  int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
  int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
  int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

  int ans = 2 * (n - rows.size());

  for (auto &[row, reserved] : rows) {
    bool leftFree = (reserved & leftMask) == 0;
    bool middleFree = (reserved & middleMask) == 0;
    bool rightFree = (reserved & rightMask) == 0;

    if (leftFree && rightFree) {
      ans += 2;
    } else if (leftFree || middleFree || rightFree) {
      ans += 1;
    }
  }

  return ans;
}

int main() {
  int temp;
  int n = 3;
  std::vector<std::vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8},
                                                 {2, 6}, {3, 1}, {3, 10}};

  temp = maxNumberOfFamilies(n, reservedSeats);
  std::cout << temp << '\n';
  return 0;
}
