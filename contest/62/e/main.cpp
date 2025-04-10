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
//

map<char,int>to;
map<int,char>unto;
vector<int> mult(vector<int>&v, vector<vector<int>>&mat) {
    vector<int> res(v.size());
    int n = v.size();
    for(int i = 0; i < n; i++) {
        int acc = 0;
        for(int j = 0; j < n; j++) {
            acc += mat[i][j] * v[j];
            acc%= 37;
        }
        res[i] = acc;
    }
    return res;

}
void solution() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(auto &i: mat) {
        for(auto &j: i) {
            cin >> j;
        }
    }
    string word;
    getline(cin, word);
    getline(cin, word);
    while(word.size() % n !=0) {
        word.push_back(' ');
    }
    vector<vector<int>> vec(word.size() / n, vector<int>(n));

    for(int i =0; i < word.size(); i++) {
        vec[i/n][i%n]=to[word[i]]; 
    }
    vector<vector<int>> res(vec.size());
    for(int i = 0; i < vec.size(); i++){
        res[i] = mult(vec[i],mat);
    }
    string ans;
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            ans.push_back(unto[res[i][j]]);
        }
    }
    cout << ans << endl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    //
    int last = -1;
    for(char i = 'A'; i <= 'Z';i++) {
        to[i]=i-'A';
        last = to[i];
        unto[to[i]] = i;
    }
    int new_last = -1;
    for(char i = '0'; i <= '9';i++){
        to[i]=i-'0'+last+1;
        new_last = to[i];
        unto[to[i]] = i;
    }
    to[' ']=new_last+1;
    unto[to[' ']] = ' ';
    solution();

    return 0;
}
