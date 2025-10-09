#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct BIT {
	vector<int> base;
	int size;
	BIT(int size) : base(size + 1), size(size) {}
	void update(int pos, int delta) {
		pos++;
		for (; pos <= size; pos += (-pos & pos)) { base[pos] += delta; }
	}
	int query(int left, int right) { return query(right) - query(left - 1); }
	int query(int right) {
		int acc = 0;
		right++;
		for (; right > 0; right -= (-right & right)) { acc += base[right]; }
		return acc;
	}
};
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> possibles;
	for (auto &[f, s] : a) {
		cin >> f >> s;
		possibles.push_back(f);
		possibles.push_back(s);
	}
	ranges::sort(possibles);
	possibles.erase(unique(possibles.begin(), possibles.end()),
	                possibles.end());
	unordered_map<int, int> first_conv;
	int i = 0;
	for (auto it = possibles.begin(); it != possibles.end(); it++) {
		first_conv[*it] = i;
		i++;
	}
	for (int i = 0; i < n; i++) {
		a[i].first = first_conv[a[i].first];
		a[i].second = first_conv[a[i].second];
	}
	map<pair<int, int>, int> conv;
	for (int i = 0; i < n; i++) { conv[a[i]] = i; }
	vector<int> it_cont(n);
	vector<int> cont_it(n);

	vector<vector<int>> interv(first_conv.size());
	BIT bit(first_conv.size());

	for (int i = 0; i < n; i++) { interv[a[i].first].push_back(a[i].second); }
	for (int i = 0; i < n; i++) { bit.update(a[i].second, 1); }
	int last = -1;
	for (int i = 0; i < first_conv.size(); i++) { ranges::sort(interv[i]); }

	for (int begin = 0; begin < interv.size(); begin++) {
		if (last != -1) {
			for (int end : interv[last]) { bit.update(end, -1); }
		}
		last = begin;
		for (int end : interv[begin]) {
			int actual = bit.query(begin, end);
			it_cont[conv[{begin, end}]] = actual - 1;
		}
	}
	bit = BIT(first_conv.size());
	for (int i = 0; i < interv.size(); i++) {
		for (int j = interv[i].size() - 1; j >= 0; j--) {
			int value = interv[i][j];
			int actual = bit.query(value, first_conv.size() - 1);
			cont_it[conv[{i, value}]] = actual;
			bit.update(value, 1);
		}
	}
	for (int i = 0; i < n; i++) { cout << it_cont[i] << " "; }
	cout << endl;
	for (int i = 0; i < n; i++) { cout << cont_it[i] << " "; }
	cout << endl;
}
