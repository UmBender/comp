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

const int MAX_VAL = 200005;

i32 main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> freq(MAX_VAL, 0);
    int         mmax = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        freq[a]++;
        if (a > mmax) { mmax = a; }
    }

    for (int i = mmax - 1; i >= 1; i--) { freq[i] += freq[i + 1]; }

    vector<int> res;
    res.reserve(mmax + 100);

    int carry = 0;

    for (int i = 0; i < mmax || carry > 0; i++) {
        int current_sum = carry;

        if (i < mmax) { current_sum += freq[i + 1]; }

        res.push_back(current_sum % 10);
        carry = current_sum / 10;
    }

    reverse(res.begin(), res.end());

    for (int digit : res) { cout << digit; }
    cout << endl;

    return 0;
}
