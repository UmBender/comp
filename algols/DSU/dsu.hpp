#pragma once
#include <map>
#include <vector>

struct dsu {
private:
  std::vector<int> Parent;
  std::vector<int> size_set;

public:
  dsu(int size) : Parent(size), size_set(size, 1) {
    for (int i = 0; i < size; i++) {
      Parent[i] = i;
    }
  }
  int size() { return Parent.size(); }

  int find_parent(int i) {
    if (i == Parent[i]) {
      return i;
    }
    Parent[i] = find_parent(i);

    return Parent[i];
  }

  void join(int i, int j) {
    i = find_parent(i);
    j = find_parent(j);
    if (size_set[i] < size_set[j]) {
      Parent[i] = j;
    } else {
      Parent[j] = i;
    }
  }

  bool same(int i, int j) {
    i = find_parent(i);
    j = find_parent(j);
    return i == j;
  }
};
