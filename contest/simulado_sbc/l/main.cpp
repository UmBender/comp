#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

struct Sieve {
  vector<int32_t> lp;
  vector<int32_t> pr;

  Sieve() {}

  Sieve(int n) { setup(n); }

  void setup(int n) {
    lp.resize(n + 1);
    pr.clear();
    for (int i = 2; i <= n; i++) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= n; j++) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
          break;
        }
      }
    }
  }

  inline bool is_prime(int p) { return lp[p] == p; }

  inline int prime(int idx) { return pr[idx]; }
};

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bs(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == target) {
      return middle;
    }

    if (arr[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

#include "dsu.hpp"
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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  return 0;
}
