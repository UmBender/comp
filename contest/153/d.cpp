#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, q;

    cin >> x >> q;
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long>> right;
    left.push(x);

    auto add = [&](int val) {
        if (left.empty() || val <= left.top()) {
            left.push(val);
        } else {
            right.push(val);
        }
    };

    auto reb = [&]() {
        while (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        while (left.size() < right.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    };
    for (int qq = 0; qq < q; qq++) {
        int a, b;
        cin >> a >> b;
        add(a);
        add(b);
        reb();
        cout << left.top() << endl;
    }
}
