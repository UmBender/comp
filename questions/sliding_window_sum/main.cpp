#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    ll acc = 0;
    ll ans = 0;

    queue<ll> elements;
    elements.push(x);
    acc += x;
    while (elements.size() < k) {
        elements.push((elements.back() * a + b) % c);
        acc += elements.back();
        n--;
    }
    while(n--) {
        ans ^= acc;
        int temp = (elements.back() * a + b) % c;
        elements.push(temp);
        acc += temp;
        acc -= elements.front();
        elements.pop();
    }
    cout << ans << endl;

    return 0;
}
