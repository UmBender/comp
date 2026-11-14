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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &ai : a) cin >> ai;
    for (int &bi : b) cin >> bi;
    if (a == b) {
        cout << "Yes" << endl;
        return;
    }
    {
        auto first = a, second = b;
        sort(begin(first), end(first));
        sort(begin(second), end(second));
        if (first != second) {
            cout << "No" << endl;
            return;
        }
    }
    a.push_back(1);
    b.push_back(1);
    int first = -1, last = -1;
    for (int i = 0; i <= n; i++) {
        if (a[i] != b[i]) {
            first = i;
            break;
        }
    }
    for (int i = n; i >= 0; i--) {
        if (a[i] != b[i]) {
            last = i;
            break;
        }
    }
    if (first == last) {
        cout << "No" << endl;
        return;
    }
    bool type1 = b[first] == a[last], type2 = b[last] == a[first];
    for (int i = first; i < last; i++) {
        if (a[i] != b[i + 1]) {
            type1 = false;
            break;
        }
    }
    for (int i = first; i < last; i++) {
        if (a[i + 1] != b[i]) {
            type2 = false;
            break;
        }
    }
    if (!type1 && !type2) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
