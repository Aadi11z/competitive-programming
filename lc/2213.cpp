#include <bits/stdc++.h>

struct Node {
  int left;
  int right;

  int prefix;
  int suffix;
  int best;
};

std::vector<Node> tree;

void merge(int node, std::string s);

void build(int node, int l, int r, std::string s) {
  tree[node].left = l;
  tree[node].right = r;

  if (l == r) {
    tree[node].prefix = 1;
    tree[node].suffix = 1;
    tree[node].best = 1;
    return;
  }

  int mid = (l + r) / 2;

  build(node * 2, l, mid, s);
  build(node * 2 + 1, mid + 1, r, s);

  merge(node, s);
}

void merge(int node, std::string s) {
  Node &curr = tree[node];
  Node &left = tree[node * 2];
  Node &right = tree[node * 2 + 1];

  curr.prefix = left.prefix;
  curr.suffix = right.suffix;

  curr.best = std::max(left.best, right.best);

  int leftLength = left.right - left.left + 1;
  int rightLength = right.right - right.left + 1;

  if (s[left.right] == s[right.left]) {
    curr.best = std::max(curr.best, left.suffix + right.prefix);

    if (left.prefix == leftLength) {
      curr.prefix = leftLength + right.prefix;
    }

    if (right.suffix == rightLength) {
      curr.suffix = rightLength + left.suffix;
    }
  }
}

void update(int node, int index, std::string s) {
  int l = tree[node].left;
  int r = tree[node].right;

  if (l == r)
    return;

  int mid = (l + r) / 2;

  if (index <= mid) {
    update(node * 2, index, s);
  } else {
    update(node * 2 + 1, index, s);
  }

  merge(node, s);
}

std::vector<int> longestRepeating(std::string s, std::string queryCharacters,
                                  std::vector<int> &queryIndices) {
  int n = s.size();
  tree.resize(4 * n);

  build(1, 0, n - 1, s);
  std::vector<int> answer;

  for (size_t i = 0; i < queryIndices.size(); i++) {
    int index = queryIndices[i];
    s[index] = queryCharacters[i];
    update(1, index, s);
    answer.push_back(tree[1].best);
  }

  return answer;
}

int main() {
  std::string s = "babacc";
  std::string queryCharacters = "bcb";
  std::vector<int> queryIndices = {1, 3, 3};

  std::vector result = longestRepeating(s, queryCharacters, queryIndices);

  for (int n : result) {
    std::cout << n << " ";
  }
  std::cout << '\n';

  return 0;
}
