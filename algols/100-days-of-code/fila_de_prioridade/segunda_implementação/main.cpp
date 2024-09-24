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

template <typename T> struct Node {
  Node *nextNode;
  T vals;
  int prior;
  static Node *newNode(T attr, int prior) {
    Node *n = new Node;
    n->vals = attr;
    n->nextNode = nullptr;
    n->prior = prior;
    return n;
  }
};

template <typename T> struct FilaDePrioridade {
  Node<T> *root;
  size_t size;
  FilaDePrioridade() : size(0), root(nullptr) {}

  void push(T val, int prior) {
    size++;

    Node<T> *holder = root;
    root = Node<T>::newNode(val, prior);
    root->nextNode = holder;
  }

  T get_val() {
    Node<T> *max_node = root;
    Node<T> *max_back = root;
    Node<T> *actual_node = root;
    Node<T> *back_node = root;
    while (actual_node) {
      if (actual_node->vals > max_node->vals) {
        max_back = back_node;
        max_node = actual_node;
      }
      back_node = actual_node;
      actual_node = actual_node->nextNode;
    }

    if (max_node == root) {
      Node<T> *hold = root;
      root = root->nextNode;
      return hold->vals;
    }

    max_back->nextNode = max_node->nextNode;

    T val = max_node->vals;
    delete max_node;
    return val;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  FilaDePrioridade<int> f;
  f.push(15, 15);
  f.push(17, 17);
  f.push(12, 12);
  f.push(13, 13);
  f.push(14, 14);
  cout << f.get_val() << endl;
  cout << f.get_val() << endl;
  cout << f.get_val() << endl;
  cout << f.get_val() << endl;
  cout << f.get_val() << endl;
  return 0;
}
