#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)

template <typename T> struct Heap {
  size_t size, used;

  pair<int, T> *heap;
  Heap(size_t size) : size(size), used(0) { heap = new pair<int, T>[size + 1]; }
  ~Heap() { delete heap; }
  void insert(T val, int prior) {
    used++;
    int pos = used;
    heap[pos] = make_pair(val, prior);
    while (pos / 2 && heap[pos].second > heap[pos / 2].second) {
      swap(heap[pos], heap[pos / 2]);
      pos /= 2;
    }
  }
  T get_val() {
    T return_value = heap[1].first;
    heap[1] = heap[used];
    used--;
    int k = 1;
    while (2 * k <= used && (heap[k].second < heap[k * 2].second ||
                             heap[k].second < heap[k * 2 + 1].second)) {
      if (heap[2 * k] > heap[2 * k + 1]) {
        swap(heap[k], heap[2 * k]);
        k *= 2;
      } else {
        swap(heap[k], heap[2 * k + 1]);
        k *= 2;
        k++;
      }
    }
    return return_value;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Heap<int> vals(256);
  vals.insert(12, 12);
  vals.insert(13, 13);
  vals.insert(11, 11);
  vals.insert(10, 10);
  vals.insert(15, 15);
  cout << "HERE" << endl;
  cout << vals.get_val() << endl;
  cout << vals.get_val() << endl;
  vals.insert(17, 17);
  vals.insert(18, 18);
  cout << vals.get_val() << endl;
  cout << vals.get_val() << endl;
  cout << vals.get_val() << endl;
  cout << vals.get_val() << endl;
  cout << vals.get_val() << endl;
  return 0;
}
