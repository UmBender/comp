#include <atcoder/all>
#include <bits/stdc++.h>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)

void correct(vector<int64_t> &arr, int64_t pos) {
  if (pos > 1) {
    if (arr[pos - 1] > arr[pos / 2 - 1])
      swap(arr[pos / 2 - 1], arr[pos - 1]);

    correct(arr, pos / 2);

    if (arr[pos / 2 - 1] < arr[pos - 1])
      swap(arr[pos / 2 - 1], arr[pos - 1]);
  }
}

void heapfy(vector<int64_t> &arr) {
  int size = arr.size();
  while (size) {
    correct(arr, size);
    size--;
  }
}

void correct(vector<int64_t> &arr, int64_t pos, int64_t limit) {
  if (pos * 2 + 1 < limit) {
    int64_t left = arr[pos * 2 - 1];
    int64_t right = arr[pos * 2];

    if (left > arr[pos - 1] || right > arr[pos - 1]) {
      if (left > right) {
        swap(arr[pos * 2 - 1], arr[pos - 1]);
        correct(arr, pos * 2, limit);

      } else {
        swap(arr[pos * 2], arr[pos - 1]);
        correct(arr, pos * 2 + 1, limit);
      }
    }
  } else if (pos * 2 < limit) {
    if (arr[pos * 2 - 1] > arr[pos - 1]) {
      swap(arr[pos * 2 - 1], arr[pos - 1]);
    }
  }
}

void heap_sort(vector<int64_t> &arr) {
  heapfy(arr);

  int64_t back = arr.size();

  while (back > 3) {
    swap(arr[back - 1], arr[0]);
    correct(arr, 1, back - 1);
    back--;
  }
  
  if(arr[0] > arr[2])
    swap(arr[0], arr[2]);

  if(arr[1] > arr[2]) 
    swap(arr[1], arr[2]);

  if (arr[0] > arr[1]) 
    swap(arr[0], arr[1]);
  
}

int64_t solution() {
  int64_t size = 20000;

  vector<int64_t> values(size, 0);
  for (int i = 1; i < size; i++) {
    values[i] = rand();
  }

  vector<int64_t> same_values = values;
  if (same_values != values)
    return 1;
  sort(same_values.begin(), same_values.end());
  heap_sort(values);

  if (values == same_values) {
    return 1;
  } else {
    cout << "SHOULD: ";
    for (int i = 0; i < same_values.size(); i++) {
      cout << same_values[i] << " \n"[i == same_values.size() - 1];
    }
    cout << "IS: ";
    for (int i = 0; i < values.size(); i++) {
      cout << values[i] << " \n"[i == values.size() - 1];
    }
    return 0;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  srand(42);

  int64_t counter = 0;
  int64_t iterations = 10000;

  for (int i = 0; i < iterations; i++) {
    counter += solution();
  }

  if (counter == iterations) {
    cout << "OKAY" << endl;
  } else {
    cout << "ERROR" << endl;
    cout << iterations - counter << endl;
  }

  return 0;
}
