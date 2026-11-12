#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

constexpr int MOD = 1e9 + 7;
constexpr int LEN = 1e6 + 100;
constexpr int MAXN = 5010;

struct Node {
    int cnt = 0;
    array<int, 26> next;
    Node() { next.fill(-1); }
};

vector<Node> trie = vector<Node>(LEN);
int actual = 1;

int dp[MAXN];

void add(string &s) {
    int node = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (trie[node].next[ch] == -1) { trie[node].next[ch] = actual++; }
        node = trie[node].next[ch];
    }
    trie[node].cnt = 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> s;
    n = s.size();
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;
        add(t);
    }

    for (int i = n - 1; i >= 0; i--) {
        int node = 0;
        for (int j = i; j < n; j++) {
            int ch = s[j] - 'a';
            node = trie[node].next[ch];
            if (node == -1) { break; }
            if (j == n - 1) {
                dp[i] += trie[node].cnt;
                dp[i] %= MOD;
                continue;
            }
            if (trie[node].cnt) {
                dp[i] += dp[j + 1];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[0] % MOD << endl;

    return 0;
}
