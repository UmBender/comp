#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

#define int i64
#define all(x) x.begin(), x.end()


bool is_lower(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    string result;
    cin >> result;
    return result == "YES";
}

void merge_sort(vector<int>& values, int left, int right) {
    if (right <= left) {
        return;
    }
    int middle = (left + right) / 2;
    merge_sort(values, left, middle);
    merge_sort(values, middle + 1, right);

    vector<int> temp(right - left + 1);
    int i = 0;
    int tl = left, tr = middle + 1;
    while (tl <= middle && tr <= right) {
        bool result = is_lower(values[tl], values[tr]);
        if (result) {
            temp[i++] = values[tl++];
        } else {
            temp[i++] = values[tr++];
        }
    }

    while (tl <= middle) {
        temp[i++] = values[tl++];
    }
    while (tr <= right) {
        temp[i++] = values[tr++];
    }
    for (int i = 0; i < right - left + 1; i++) {
        values[i + left] = temp[i];
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> pt(n);
    iota(all(pt), 1);
    merge_sort(pt, 0, n - 1);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[pt[i] - 1] = i + 1;
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
    cout.flush();

    return 0;
}
