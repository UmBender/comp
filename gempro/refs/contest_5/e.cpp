#include <bits/stdc++.h>

using namespace std;

using i32 = int;
using i64 = long long;
#define int i64
#define all(x) x.begin(), x.end()


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> elements;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 10; j++) {
            int acc = 0;
            for (int k = 0; k <=j; k++) {
                acc *= 10;
                acc += i;
            }
            elements.push_back(acc);
        }
    }

    sort(elements.begin(), elements.end());
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int counter = 0;
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i] <= n) {
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
