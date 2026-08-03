#include <iostream>

void print_command(int n) {
  if (n--) {
    std::cout << "I love Recursion" << '\n';
    print_command(n);
  }
}

int main() {
  int n;
  std::cin >> n;

  print_command(n);

  return 0;
}
