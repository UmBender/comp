#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64

struct event {
    int type;
    int l, r, id;
    bool operator<(const event& other) const {
        if (l != other.l) {
            return l > other.l;
        }
        return type < other.type;
    }
};

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

signed main() {
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> bl(n + 1);
    vector<vector<pair<int, int>>> br(n + 1);
    vector<event> events;

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        bl[l].insert(bl[l].end(), {r, i});
        br[r].insert(br[r].end(), {l, i});
        events.insert(events.end(), {0, l, r, i});
    }

    for (int i = 1; i <= n; i++) {
        if (!byl[i].empty()) {
            sort(byl[i].begin(), byl[i].end());
        }
        if (!byr[i].empty()) {
            sort(byr[i].begin(), byr[i].end());
        }
    }

    int q;
    cin >> q;
    vector<int> ans(q + 1, -1);

    for (int i = 1; i <= q; i++) {
        int s, t;
        cin >> s >> t;

        int maxr = -1;
        int ida = -1;

        int lowa = 0;
        int higha = byl[s].size();
        higha--;
        while (lowa <= higha) {
            int mid = lowa + (higha - lowa) / 2;
            if (byl[s][mid].first <= t) {
                maxr = byl[s][mid].first;
                ida = byl[s][mid].second;
                lowa = mid + 1;
            } else {
                higha = mid - 1;
            }
        }

        int minl = 2e18;
        int idb = -1;

        int lowb = 0;
        int highb = byr[t].size();
        highb--;
        while (lowb <= highb) {
            int mid = lowb + (highb - lowb) / 2;
            if (byr[t][mid].first >= s) {
                minl = byr[t][mid].first;
                idb = byr[t][mid].second;
                highb = mid - 1;
            } else {
                lowb = mid + 1;
            }
        }

        if (ida == -1 || idb == -1) {
            ans[i] = 0;
        } else {
            if (ida != idb) {
                if (minl <= maxr + 1) {
                    ans[i] = 1;
                } else {
                    ans[i] = 0;
                }
            } else {
                events.insert(events.end(), {1, s, t, i});
            }
        }
    }

    sort(events.begin(), events.end());
    BIT bit(n + 1);

    for (auto& i : events) {
        if (i.type == 0) {
            bit.add(i.r, 1);
        } else {
            int count = bit.query(i.r);
            if (count >= 2) {
                ans[i.id] = 1;
            } else {
                ans[i.id] = 0;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        if (ans[i] == 1) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
