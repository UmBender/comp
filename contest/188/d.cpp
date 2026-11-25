#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int r, c;
        cin >> r >> c;

        vii possi = {{1, 1}, {1, m}, {n, 1}, {n, m}};
        vi ord = {0, 1, 2, 3};
        int mmin = 1e15;
        do {
            int acc = 0;
            int lx = c, ly = r;
            for (int i = 0; i < 4; i++) {
                auto [ny, nx] = possi[ord[i]];
                int one = max(abs(lx - nx), abs(ly - ny));
                acc += one;
                lx = nx, ly = ny;
            }
            mmin = min(acc, mmin);

        } while (next_permutation(begin(ord), end(ord)));
        cout << mmin << endl;
    }
    return 0;
}
