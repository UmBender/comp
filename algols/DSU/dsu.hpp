#pragma once
#include <map>
#include <numeric>
#include <vector>

struct DSU {
private:
  std::vector<int> parent;
  std::vector<int> sizes;

public:
  DSU(int size) : parent(size + 1), sizes(size + 1, 1) {
    std::iota(parent.begin(), parent.end(), 0);
  }

  inline int size() { return parent.size() - 1; }

  int find_parent(int i) {
    if (i == parent[i]) {
      return i;
    }

    parent[i] = find_parent(parent[i]);

    return parent[i];
  }

  void join(int i, int j) {
    i = find_parent(i);
    j = find_parent(j);

    if (i == j)
      return;
    if (sizes[i] < sizes[j])
      std::swap(i, j);

    sizes[i] += sizes[j];
    parent[j] = i;
  }

  bool same(int i, int j) {
    i = find_parent(i);
    j = find_parent(j);
    return i == j;
  }

  int get_size(int set){
    return sizes[find_parent(set)];
  }
};
