#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;

// Title: Cartesian tree (max)
// Description: Parent of each index in the max Cartesian tree of a vector (maximum at the root, -1
// for it). Usage:
//   vector<int> par = maxCartesianTree(a);   // ties: the leftmost one is the ancestor
//   In-order traversal of the tree is 0, 1, ..., n - 1.
// Complexity: O(n).
template <class T> vector<int> maxCartesianTree(const vector<T> &a) {
    int n = (int)a.size();
    vector<int> par(n, -1), st; // st: the right spine, top = deepest
    for (int i = 0; i < n; i++) {
        int last = -1;
        while (!st.empty() && a[st.back()] < a[i]) last = st.back(), st.pop_back();
        if (last != -1) par[last] = i; // the popped chain becomes i's left subtree
        if (!st.empty()) par[i] = st.back();
        st.push_back(i);
    }
    return par;
}
// End: Cartesian tree (max)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, vector<int>> prefs;
    vector<int> pref(n + 1);
    prefs[0].push_back(0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] ^ a[i];
        prefs[pref[i + 1]].push_back(i + 1);
    }
    auto cart = maxCartesianTree(a);
    vector<vector<int>> childs(n);
    vector<int> left(n), right(n);
    int root = 0;
    for (int i = 0; i < n; i++) {
        dbg(i, cart[i]);
        if (cart[i] == -1) {
            root = i;
            continue;
        }
        childs[cart[i]].push_back(i);
    }

    stack<pair<int, int>> sp;
    sp.push({root, 0});
    right[root] = root;
    left[root] = root;

    while (!sp.empty()) {
        auto &[actual, cnt] = sp.top();
        if (cnt == childs[actual].size()) {
            if (cart[actual] != -1) {
                left[cart[actual]] = min(left[cart[actual]], left[actual]);
                right[cart[actual]] = max(right[cart[actual]], right[actual]);
            }
            sp.pop();
            continue;
        }
        auto next = childs[actual][cnt++];
        left[next] = next;
        right[next] = next;
        sp.emplace(next, 0);
    }

    ll cnt = 0;

    auto cntRange = [&](int actual, int l, int r) -> ll {
        auto it = prefs.find(actual);
        if (it == prefs.end()) return 0;
        auto &pos = it->second;
        return upper_bound(begin(pos), end(pos), r) - lower_bound(begin(pos), end(pos), l);
    };

    for (int i = n - 1; i >= 0; i--) {
        int leftCnt = i - left[i];
        int rightCnt = right[i] - i;
        if (leftCnt <= rightCnt) {
            for (int l = left[i]; l <= i; l++) {
                int target = pref[l] ^ a[i];
                cnt += cntRange(target, i + 1, right[i] + 1);
            }
        } else {
            for (int r = i; r <= right[i]; r++) {
                int target = pref[r + 1] ^ a[i];
                cnt += cntRange(target, left[i], i);
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
