#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> prefj2Aj(n + 1);
    vector<int> prefjAj(n + 1);
    vector<int> prefAj(n + 1);
    for (int i = 0; i < n; i++) {
        prefj2Aj[i + 1] = prefj2Aj[i] + (i + 1) * (i + 1) * a[i];
        prefjAj[i + 1] = prefjAj[i] + (i + 1) * a[i];
        prefAj[i + 1] = prefAj[i] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        sum += -(prefj2Aj[r] - prefj2Aj[l - 1]);
        sum += (r + l) * (prefjAj[r] - prefjAj[l - 1]);
        sum += (r + 1) * (1 - l) * (prefAj[r] - prefAj[l - 1]);
        cout << sum << endl;
    }

    return 0;
}
