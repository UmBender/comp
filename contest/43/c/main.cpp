// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

bool its_possible(int n, int size) {
  if(size > 60) {
    return true;
  }
  if ((1ll << (size-1)) < n) {
    return false;
  }
  return true;
}

vector<char> vectorize(int n, int size) {
  vector<char> elements;
  while (n) {
    if (n & 1) {
      elements.push_back('b');
    } else {
      elements.push_back('f');
    }
    n /= 2;
  }
  while (elements.size() < size - 1) {
    elements.push_back('f');
  }

  reverse(elements.begin(), elements.end());
  return elements;
}

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<char> steps;
  int actual = 1;
  int i, j;
  i = 0, j = n - 1;
  if(!its_possible(k, n)) {
    cout << -1 << endl;
    return;
  }
  vector<char> ops = vectorize(k - 1, n);
  for (int k = 0; k < ops.size(); k++) {
    if (ops[k] == 'f') {
      a[i] = actual;
      i++;
      actual++;
    } else {
      a[j] = actual;
      j--;
      actual++;
    }
  }
  a[j] = n;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
