#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;

constexpr int MAXN = 2e5 + 100;
struct FenwickTree {

    vector<int> tree;
    FenwickTree() : tree(MAXN) {}

    void add(int pos, int delta) {
        for (pos++; pos < MAXN; pos += (-pos & pos)) { tree[pos] += delta; }
    }

    int query(int right) {
        int acc = 0;
        for (right++; right > 0; right -= (-right & right)) { acc += tree[right]; }
        return acc;
    }

    int query(int left, int right) {
        if (left > right) return 0;
        return query(right) - query(left - 1);
    }
};

using Nodes = array<int, 3>;

int32_t main() {
    int n, q;
    cin >> n >> q;
    vi x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vii queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--, queries[i].second--;
    }
    vii rev = queries;
    vi ans(q);
    sort(begin(rev), end(rev));
    auto getAns = [&](pii key) -> int & {
        int pos = lower_bound(begin(rev), end(rev), key) - begin(rev);
        return ans[pos];
    };
    vector<Nodes> sp;
    int pos = q - 1;
    int begin = n;
    FenwickTree costs, sums;
    for (int i = 0; i < n; i++) { sums.add(i, x[i]); }

    auto query = [&](int posi) -> int {
        if (posi == sp.back()[0]) { return 0; }

        Nodes temp = {posi + 1, 0, 0};
        auto it = lower_bound(rbegin(sp), rend(sp), temp);
        it--;

        int pos = sp.size() - 1 - (it - rbegin(sp));
        int pre = costs.query(pos + 1, sp.size() - 1);

        int len = posi - sp[pos][0] + 1;
        int first = len * sp[pos][1];
        int second = sums.query(sp[pos][0], posi);
        return pre + (first - second);
    };
    while (pos >= 0) {
        while (rev[pos].first < begin) {
            begin--;
            while (!sp.empty() && sp.back()[1] < x[begin]) {
                int temp = costs.query(sp.size() - 1, sp.size() - 1);
                costs.add(sp.size() - 1, -temp);
                sp.pop_back();
            }
            int end = sp.empty() ? n : sp.back()[0];
            int cost = x[begin] * (end - begin) - sums.query(begin, end - 1);
            costs.add(sp.size(), cost);
            sp.push_back({begin, x[begin], cost});
        }
        getAns(rev[pos]) = query(rev[pos].second);
        pos--;
    }
    for (int i = 0; i < q; i++) { cout << getAns(queries[i]) << endl; }
}
