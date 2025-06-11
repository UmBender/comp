// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;
// clang-format on
#define EVEN 0LL
#define ODD 1LL

void show(vector<vector<int>> prefix[2]) {
    cout << "EVEN" << endl;
    for (int i = 0; i <= 'z' - 'a'; i++) {
        cout << static_cast<char>(i + 'a') << " ";
        for (int j = 0; j < prefix[EVEN].size(); j++) {
            cout << prefix[EVEN][j][i] << " ";
        }
        cout << endl;
    }
    cout << "ODD" << endl;
    for (int i = 0; i <= 'z' - 'a'; i++) {
        cout << static_cast<char>(i + 'a') << " ";
        for (int j = 0; j < prefix[ODD].size(); j++) {
            cout << prefix[ODD][j][i] << " ";
        }
        cout << endl;
    }
}

void solution() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        vector<vector<int>> counter[2];
        counter[EVEN] = vector((n + 1) / 2, vector<int>(26));
        counter[ODD]  = vector(n / 2, vector<int>(26));

        for (int i = 0; i < n; i++) {
            if (i & ODD) {
                counter[ODD][i / 2][s[i] - 'a']++;

            } else {

                counter[EVEN][i / 2][s[i] - 'a']++;
            }
        }
        vector<vector<int>> prefix[2];
        prefix[EVEN] = vector(counter[EVEN].size() + 1, vector<int>(26));
        prefix[ODD]  = vector(counter[ODD].size() + 1, vector<int>(26));
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < prefix[i].size(); j++) {
                for (int k = 0; k < 26; k++) {
                    prefix[i][j][k] =
                        prefix[i][j - 1][k] + counter[i][j - 1][k];
                }
            }
        }
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            vector<int> joined[2];
            for (int j = 0; j < 2; j++) {
                joined[j] = vector<int>(26);
            }
            int removed_from = i & 1;
            int even_limit_1, even_limit_2;
            int odd_limit_1, odd_limit_2;
            if (removed_from == ODD) {
                even_limit_1 = i / 2;
                even_limit_2 = i / 2 + 1;
                odd_limit_1  = i / 2 - 1;
                odd_limit_2  = i / 2 + 1;
            } else {
                even_limit_1 = i / 2 - 1;
                even_limit_2 = i / 2;
                odd_limit_1  = i / 2 - 1;
                odd_limit_2  = i / 2 + 1;
            }
            for (int j = 0; j < 26; j++) {
                joined[ODD][j] =
                    prefix[ODD][odd_limit_1 + 1][j] - prefix[ODD][0][j];
                joined[ODD][j] +=
                    prefix[EVEN].back()[j] - prefix[EVEN][odd_limit_2][j];
                joined[EVEN][j] =
                    prefix[EVEN][even_limit_1 + 1][j] - prefix[EVEN][0][j];
                joined[EVEN][j] +=
                    prefix[ODD].back()[j] - prefix[ODD][even_limit_2][j];
            }
            int mmax[2] = {0, 0};
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 2; k++) {
                    mmax[k] = max(mmax[k], joined[k][j]);
                }
            }
            for (int j = 0; j < 2; j++) {
                mmax[j] = n / 2 - mmax[j];
            }
            /*
            cout << "CASE_EVEN, CASE_ODD: " << even_limit_1 << " "
                 << even_limit_2 << " " << odd_limit_1 << " " << odd_limit_2
                 << endl;
            
            for (int j = 0; j < 2; j++) {
                cout << "CASE" << j << endl;
                for (int k = 0; k < 26; k++) {
                    cout << static_cast<char>(k + 'a') << ": " << joined[j][k]
                         << endl;
                }
            }
            */
            dp[i] = mmax[ODD] + mmax[EVEN];
        }
        int mmin = MAX_INT;
        for (int i : dp) {
            mmin = min(mmin, i);
        }
        cout << mmin + 1 << endl;

    } else {
        map<char, int> evens;
        map<char, int> odds;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                odds[s[i]]++;
            } else {
                evens[s[i]]++;
            }
        }
        int maxx_odds = 0;
        int maxx_even = 0;
        for (auto [_, j] : evens) {
            maxx_even = max(maxx_even, j);
        }
        for (auto [_, j] : odds) {
            maxx_odds = max(maxx_odds, j);
        }
        int correct_odds  = n / 2 - maxx_odds;
        int correct_evens = n / 2 - maxx_even;
        cout << correct_evens + correct_odds << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
