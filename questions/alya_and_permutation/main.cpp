// #include <atcoder/all>
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
    do {                                                                       \
        cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                      \
        __dbg(__VA_ARGS__);                                                    \
    } while (0)

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
// using mint = atcoder::modint;
void odd(int x) {
    cout << x << endl;
    int l = x & -x;
    vector<int> p(x);
    set<int> values;
    p.back() = x;
    values.insert(x);
    p[x - 2] = x - 1;
    values.insert(x - 1);
    p[x - 3] = l * 2 + l;
    values.insert(l * 2 + l);
    p[x - 4] = l;
    values.insert(l);
    int actual_num = 1;
    for (int i = x - 5; i >= 0; i--) {
        bool seted = false;
        while (!seted) {
            if (values.count(actual_num)) {
                actual_num++;
            } else {
                p[i] = actual_num;
                actual_num++;
                seted = true;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        cout << p[i] << " \n"[i == x - 1];
    }
}
void power2(int x) {
    cout << (x*2)-1<< endl;
    set<int> used;
    vector<int> p(x);
    p[x - 1] = x;
    p[x - 2] = x - 1;
    p[x - 3] = x - 2;
    p[x - 4] = 3;
    p[x - 5] = 1;
    used.insert(x);
    used.insert(x - 1);
    used.insert(x - 2);
    used.insert(3);
    used.insert(1);
    int actual = 1;
    for (int i = 0; i < x - 5; i++) {
        bool seted = false;
        while (!seted) {
            if (used.count(actual)) {
                actual++;
            } else {
                p[i] = actual;
                actual++;
                seted = true;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        cout << p[i] << " \n"[i == x - 1];
    }
}
int lowp2(int x) {
    int i = 1;
    while (i * 2 < x) {
        i *= 2;
    }
    return i;
}

void npower2(int x) {
    vector<int> p(x);
    set<int> used;
    int l = lowp2(x);
    cout << (l*2)-1<<endl;
    p[x - 1] = l;
    used.insert(l);
    p[x - 2] = l - 1;
    used.insert(l - 1);
    p[x - 3] = l - 2;
    used.insert(l - 2);
    p[x - 4] = 3;
    used.insert(3);
    p[x - 5] = 1;
    used.insert(1);
    int actual = 1;
    for (int i = 0; i < x - 5; i++) {
        int seted = false;
        while (!seted) {
            if (used.count(actual)) {
                actual++;
            } else {
                p[i] = actual;
                actual++;
                seted = true;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        cout << p[i] << " \n"[i == x - 1];
    }
}
void solution() {
    int n;
    cin >> n;
    if (n & 1) {
        odd(n);
    } else {
        if ((n & (n - 1)) == 0) {
            power2(n);

        } else {
            if (n == 6) {
                cout << 7 << endl;
                cout << "2 4 5 1 3 6" << endl;
            } else {
                npower2(n);
            }
        }
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
