#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;

using namespace std;
#define int i64

signed main() {
    int n;
    cin >> n;

    auto query = [](int pos) -> char{
        cout << "? " << pos << endl;
        char color;
        cin >> color;
        return color;
    };
    char first = query(1);
    char last = query(n);
    if (first == last) {
        cout << "! " << n << endl;
        return 0;
    }
    int left = 1;
    int right = n;
    char color_left = first;
    char color_right = last;
    map<int, char> colors;
    char inverse = first == 'R' ? 'B': 'R';
    while ((right - left) > 1) {
        int middle = left + (right - left) / 2;
        char color_middle = query(middle);
        bool pair_in_left = false;
        if ((middle - left) % 2 == 0) {
            if (color_middle != color_left) {
                pair_in_left = true;
            }
        } else {
            if (color_middle == color_left) {
                pair_in_left = true;
            }
        }
        if (pair_in_left) {
            right = middle;
            color_right = color_middle;
        } else {
            left = middle;
            color_left = color_middle;

        }
    }
    cout << "! " << left << endl;

    return 0;
}
