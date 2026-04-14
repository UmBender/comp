#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define all(x) x.begin(), x.end()
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    for (auto &i: h) {
        cin >> i;
    }
    vector<vector<pair<int,int>>> qq(n);

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        qq[a].push_back({b, i});

    }

    vector<int> stack;
    vector<int> positions;
    vector<int> results(q);

    for (int i = n - 1; i >= 0; i--) {
        int actual = h[i];
        while(!stack.empty() && stack.back() <= actual) {
            stack.pop_back();
            positions.pop_back();
        }
        stack.push_back(actual);
        positions.push_back(i);

        for (auto &[end, it]: qq[i]) {
            auto iter = upper_bound(positions.rbegin(), positions.rend(), end);
            results[it] = iter - positions.rbegin();
        }
    }

    for (int i = 0; i < q; i++) 
        cout << results[i] << endl;


    return 0;
}
