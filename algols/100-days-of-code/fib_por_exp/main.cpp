#include <bits/stdc++.h>

using namespace std;

struct Mat {
  int arr[2][2];
  Mat() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        arr[i][j] = 0;
      }
    }
  }

  static Mat base() {
    Mat mat = Mat();
    mat.arr[0][0] = 0;
    mat.arr[0][1] = 1;
    mat.arr[1][0] = 1;
    mat.arr[1][1] = 1;
    return mat;
  }

  static Mat multi(Mat &first, Mat &second) {
    Mat valor = Mat();

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          valor.arr[i][j] += first.arr[i][k] * second.arr[k][j];
        }
      }
    }
    return valor;
  }
};

Mat fib_base(uint64_t n) {
  if (n == 1) {
    return Mat::base();
  }
  Mat mat = fib_base(n / 2);
  mat = Mat::multi(mat, mat);
  if (n % 2) {
    Mat base = Mat::base();
    mat = Mat::multi(mat, base);
  }

  return mat;
}

uint64_t fib(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  return fib_base(n).arr[1][1];
}

int main() {
  for (int i = 0; i < 30; i++) {
    int fibonacci = fib(i);
    cout << fibonacci << endl;
  }
  return 0;
}
