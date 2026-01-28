#include <bits/stdc++.h>
using namespace std;
using i32  = int;
using i64  = long long;
using i128 = __int128;

#define int i64

struct Obj {
    int t, x, y;
    bool operator<(const Obj& second) const { return t < second.t; }
	Obj(int tt, int xx, int yy): t(tt), x(xx), y(yy) {}
};

i32 main() {
    cin.tie(0)->sync_with_stdio(0);
    int g, n;
    cin >> g >> n;

    vector<Obj> v;
	v.reserve(g);
    for (int i = 0; i < g; i++) {
        int t, x, y;
        cin >> x >> y >> t;
		v.emplace_back(t, x, y);
    }

    sort(v.begin(), v.end());
    int counter = 0;

    auto dist = [](Obj& f, Obj& s) {
        int first  = f.x - s.x;
        int second = f.y - s.y;
        int third  = f.t - s.t;
        return first * first + second * second <= third * third;
    };

    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        Obj o = {t, x, y};

        int pos = upper_bound(v.begin(), v.end(), o) - v.begin();
        for (int i = max(pos - 1, 0ll); i <= min(pos, g - 1); i++) {
            Obj actual = v[i];
            if (!dist(o, actual) && ++counter) { break; }
        }
    }
    cout << counter << endl;

    return 0;
}
