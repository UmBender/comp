#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

struct Queue {
  vector<int> acc;
  int front;
  Queue() : acc(1), front(0) { acc[0] = 0; }
  void enqueu(int value) {
    int back = acc.back();
    acc.push_back(back + value);
  }

  void deque() { front++; }

  int head(int pos) {
    int actual_pos = front + pos;
    return acc[actual_pos] - acc[front];
  }
};

void solution() {
  int q;
  cin >> q;
  auto queue = Queue();
  while (q--) {
    int opt;
    cin >> opt;

    switch (opt) {
    case 1:
      int l;
      cin >> l;
      queue.enqueu(l);
      break;
    case 2:
      queue.deque();
      break;
    case 3:
      int k;
      cin >> k;
      cout << queue.head(k - 1) << endl;
      break;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
