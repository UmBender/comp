// #include <atcoder/all>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>

using namespace std;

#define endl '\n'
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

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
// using mint = atcoder::modint;
#define f64 long double
#define SMALL 0.000000001

struct Matrix {
  f64 mat[51][101];
  int columns;
  int rows;
  Matrix(vector<f64> &func_obj, vector<vector<f64>> &costs,
         vector<f64> &limits) {
    this->columns = costs.size() + costs.front().size() + 1;
    this->rows = limits.size() + 1;
    for (int j = 0; j < func_obj.size(); j++) {
      for (int i = 0; i < costs.front().size(); i++) {
        mat[i][j] = costs[j][i];
      }
    }
    for (int i = 0; i < limits.size(); i++) {
      for (int j = 0; j < limits.size(); j++) {
        mat[i][j + func_obj.size()] = i == j;
      }
      mat[i][func_obj.size() + limits.size()] = limits[i];
    }
    for (int i = 0; i < func_obj.size(); i++) {
      mat[rows - 1][i] = func_obj[i];
    }
    for (int i = 0; i < limits.size() + 1; i++) {
      mat[rows - 1][i + func_obj.size()] = 0;
    }
  }

  int pivot_col() {
    for (int i = 0; i < columns - 1; i++) {
      if (mat[rows - 1][i] > 0.0) {
        return i;
      }
    }
    return -1;
  }
  void solve() {
    int actual_col, actual_row;
    actual_col = pivot_col();
    while (actual_col != -1) {
      actual_row = -1;
      f64 minn = 1E9;
      for (int i = 0; i < rows - 1; i++) {
        if (mat[i][actual_col] <= SMALL) {
          continue;
        }
        if (actual_row == -1 ||
            mat[i][columns - 1] / mat[i][actual_col] < minn) {
          actual_row = i;
          minn = mat[i][columns - 1] / mat[i][actual_col];
        }
      }
      if (actual_row == -1) {
        break;
      }
      for (int i = 0; i < rows; i++) {
        if (i == actual_row) {
          f64 mult = mat[actual_row][actual_col];
          for (int j = 0; j < columns; j++) {
            mat[i][j] = mat[i][j] / mult;
          }
        } else {
          f64 mult = mat[i][actual_col] / mat[actual_row][actual_col];
          for (int j = 0; j < columns; j++) {
            mat[i][j] -= mat[actual_row][j] * mult;
            if (fabs(mat[i][j]) < SMALL) {
              mat[i][j] = 0.0;
            }
          }
        }
      }

      actual_col = pivot_col();
    }
  }

  inline f64 get_value() { return -mat[rows - 1][columns - 1]; }
  void show() {
    dbg(rows, columns);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  }
};

void solution() {
  int n, m;
  cin >> n >> m;
  vector<f64> w(n);
  for (auto &i : w) {
    cin >> i;
  }
  vector<vector<f64>> ps(m, vector<f64>(n));
  vector<f64> ts(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ps[i][j];
      ps[i][j] /= 100.00;
    }
    cin >> ts[i];
  }
  auto mat = Matrix(ts, ps, w);
  mat.solve();
  cout << fixed << setprecision(2) << mat.get_value() << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
