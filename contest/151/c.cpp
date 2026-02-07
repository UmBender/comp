#include <bits/stdc++.h>
using namespace std;
using i32  = int;
using i64  = long long;
using i128 = __int128;
using VI   = vector<i32>;
using VVI  = vector<VI>;
using PII  = pair<i32, i32>;
using VII  = vector<PII>;
using VVII = vector<VII>;

#define int i64
i32 main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    sort(a.begin(), a.end());
    map<int, int> counter;
    for (int i = 0; i < n; i++) { counter[a[i]]++; }
    int sum = 0;
    for (int i = 0; i < n; i++) { sum += a[i]; }
    vector<int> divisors;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            divisors.push_back(i);
            divisors.push_back(sum / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());

    int         mmax = a.back();
    vector<int> ans;
    for (int div : divisors) {
        if (div < mmax) { continue; }
        bool ok = true;
        for (auto& [x, cnt] : counter) {
            if (x == div) { continue; }
            int target = div - x;
            if (target == x) {
                if (cnt % 2 != 0) {
                    ok = false;
                    break;
                }
            } else {
                auto it = counter.find(target);
                if (it == counter.end() || it->second != cnt) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) { ans.push_back(div); }
    }

    for (auto i : ans) { cout << i << " "; }
    cout << endl;

    return 0;
}
