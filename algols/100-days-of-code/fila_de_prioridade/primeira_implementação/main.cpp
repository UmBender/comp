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
    if (root == nullptr) {
      root = Node<T>::newNode(val, prior);
      return;
    }
    if (root->prior < prior) {
      Node<T> *holding = root;
      root = Node<T>::newNode(val, prior);
      root->nextNode = holding;
      return;
    }
    Node<T> *caps = root;
    Node<T> *last = root;
    while (caps && caps->prior > prior) {
      last = caps;
      caps = caps->nextNode;
    }
    Node<T> *new_node = Node<T>::newNode(val, prior);
    last->nextNode = new_node;
    new_node->nextNode = caps;
  }

  T get_val() {
    Node<T> *val = root;
    root = val->nextNode;
    T holding = val->vals;
    delete val;
    return holding;
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
