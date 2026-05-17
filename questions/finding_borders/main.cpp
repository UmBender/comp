#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;
using namespace std;
#define endl '\n'
#define int i64


vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


signed main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> zArr = zFunction(s);
    vector<int> ans;
    for (int i = n - 1; i >= 1; i--) {
        int lenght = i + 1;
        if (zArr[i] + i == n) {
            ans.push_back(zArr[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}
