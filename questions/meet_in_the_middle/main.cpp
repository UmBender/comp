#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for (auto &i : t) {
        cin >> i;
    }

    vector<int> first, second;

    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            first.push_back(t[i]);
        } else {
            second.push_back(t[i]);
        }
    }
    vector<int> count1, count2;
    count1.reserve(2e6);
    count2.reserve(2e6);
    count1.push_back(0), count2.push_back(0);

    for (int i = 0; i < first.size(); i++) {
        for (int j = count1.size() - 1; j >= 0; j--) {
            count1.push_back(count1[j] + first[i]);
        }
    }

    for (int i = 0; i < second.size(); i++) {
        for (int j = count2.size() - 1; j >= 0; j--) {
            count2.push_back(count2[j] + second[i]);
        }
    }
    unordered_map<int, int> one, two;
    one.reserve(2e6);
    two.reserve(2e6);
    for (int i = 0; i < count1.size(); i++) {
        one[count1[i]]++;
    }
    for (int i = 0; i < count2.size(); i++) {
        two[count2[i]]++;
    }

    int acc = 0;
    for (auto [key, value] : one) {
        int rest = x - key;
        acc += value * two[rest];
    }
    cout << acc << endl;

    return 0;
}
