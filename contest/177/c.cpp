#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()


template<int B = 63>
struct XorBasis {
	using T = bitset<B>;
	struct Row { int i; T x, w; };
	vector<Row> b;
	T reduce(T &x, bool hi = 0) const {
		T w;
		for (auto &r: b) if (x[r.i] != hi) x ^= r.x, w ^= r.w;
		return w;
	}
	bool add(T x) {
		auto w = reduce(x);
		for (int i = B-1; i >=0; --i) if (x[i]) {
			w[sz(b)] = 1;
			int j = 0;
			while (j < sz(b) && b[j].i > i) ++j;
			b.insert(b.begin()+j,{i,x,w}); return 0;
		}
		return 1;
	}
	T query(T x = {}, bool hi = 0) const { reduce(x, hi); return x; }
};

int32_t main() {
	int n;
	cin >> n;
	vector<char> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	ll total = 0;
	vector<ll> ops(n);
	for (int i = 0; i < n; i++) {
		int actual = a[i] - 'a';
		int trs = b[i] - 'a';
		ll first =(1ll << actual); 
		ll second = (1ll << trs);

		total ^= first;
		ops[i] = first ^ second;
	}
	XorBasis<30> xb;

	vector<int> yn(n);
	for (int i = 0; i < n; i++) {
		if (!xb.add(ops[i])) {
			yn[i] = 1;
		}
	}


	auto rec = [&](vector<int> opts) -> vector<int> {
		map<char, vector<int>> pos;
		for (int i = 0; i < n; i++) {
			if (opts[i] < 0) {
				int actual = (-opts[i]) - 1;
				pos[b[actual]].push_back(opts[i]);
			} else {
				int actual = opts[i] - 1;
				pos[a[actual]].push_back(opts[i]);
			}
		}
		vector<int> ans(n);
		int middle = 1e9;
		int actual = 0;
		for (auto &[k, v]: pos) {
			if (v.size() % 2) {
				middle = v.back();
				v.pop_back();
			}
			for (int i = 0; i < v.size() / 2; i++) {
				ans[actual] = v[i * 2];
				ans[n - 1 - actual] = v[i * 2 + 1];
				actual++;
			}
		}
		if (middle != 1e9) {
			ans[actual] = middle;
		}
		return ans;
	};
	if (n % 2 == 0) {
		bitset<30> temp(total);
		auto result = xb.reduce(temp);
		if (temp == 0) {
			vector<int> letters(n);
			int j = 0;
			for (int i = 0; i < n; i++) {
				if  (yn[i]) {
					if (result[j]) {
						letters[i] = -(i + 1);
					} else {
						letters[i] = (i + 1);
					}
					j++;
					continue;
				} else {
					letters[i] = i + 1;
				}
			}
			auto ans = rec(letters);
			cout << "SIM" << endl;
			for (int i = 0; i < n; i++) {
				cout << ans[i] << " \n"[i == n-1];
			}
		} else {
			cout << "NAO" << endl;
		}
		return 0;
	}
	for (int i = 0; i < 26; i++) {
		int actual = (1ll << i);
		auto temp = bitset<30>(actual ^ total);
		auto result = xb.reduce(temp);
		if (temp == 0) {
			vector<int> letters(n);
			int j = 0;
			for (int i = 0; i < n; i++) {
				if  (yn[i]) {
					if (result[j]) {
						letters[i] = -(i + 1);
					} else {
						letters[i] = (i + 1);
					}
					j++;
					continue;
				} else {
					letters[i] = i + 1;
				}
			}
			auto ans = rec(letters);
			cout << "SIM" << endl;
			for (int i = 0; i < n; i++) {
				cout << ans[i] << " \n"[i == n-1];
			}
			return 0;
		}
	}
	cout << "NAO" << endl;



	return 0;
}
