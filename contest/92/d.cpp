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
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

int bslowermax(vector<int> &a, int value) {
	int l = 0;
	int r = a.size() - 1;
	int actual = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] > value) {
			r = m - 1;
		} else {
			actual = max(actual, m);
			l = m + 1;
		}
	}
	return actual;
}

void solution() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &i : a) { cin >> i; }
	map<int, vector<int>> vai, volta;
	map<int, int> counter;
	for (int i = 0; i < n; i++) {
		counter[a[i]]++;
		vai[a[i]].push_back(i);
	}
	if (counter.begin()->second >= k - 1) {
		cout << "YES" << endl;
		return;
	}
	auto is_pali = [](vector<int> &ax) -> bool {
		int nn = ax.size();
		for (int i = 0; i < nn; i++) {
			if (ax[i] != ax[nn - i - 1]) { return false; }
		}
		return true;
	};
	if (is_pali(a)) {
		cout << "YES" << endl;
		return;
	}
	set<pair<int, int>> cannot_remove;
	set<pair<int, int>> maybe_remove;
	set<int> cant_ele;
	set<int> maybe_ele;
	int counter_elemets = 0;
	auto actual_pos = vai.begin();
	while (actual_pos != vai.end() &&
	       counter_elemets + (int)actual_pos->second.size() < k) {
		counter_elemets += actual_pos->second.size();
		cant_ele.insert(actual_pos->first);
		for (auto i : actual_pos->second) {
			cannot_remove.insert({i, actual_pos->first});
		}
		actual_pos++;
	}

	while (actual_pos != vai.end() && counter_elemets < k) {
		counter_elemets += actual_pos->second.size();
		maybe_ele.insert(actual_pos->first);
		for (auto i : actual_pos->second) {
			maybe_remove.insert({i, actual_pos->first});
		}
		actual_pos++;
	}
	vector<int> test;
	for (auto &[i, j] : cannot_remove) { test.push_back(j); }
	if (is_pali(test) && (int)test.size() == k - 1) {
		cout << "YES" << endl;
		return;
	}
	if (!is_pali(test)) {
		cout << "NO" << endl;
		return;
	}
	int actual_size = test.size();
	vector<int> pos_n_move;
	vector<int> pos_can_move;
	set<int> used;
	for (auto &[i, j] : cannot_remove) { pos_n_move.push_back(i); }
	for (auto &[i, j] : maybe_remove) { pos_can_move.push_back(i); }
	int jmay = maybe_remove.size() - 1, imay = 0;
	int jnot = cannot_remove.size() - 1, inot = 0;
	while (imay < jmay && inot < jnot && actual_size < k - 1) {
		int left = inot;
		int right = cannot_remove.size() - jnot - 1;
		if (left < right) {
			inot++;
			continue;
		}
		if (left > right) {
			jnot++;
			continue;
		}
		if (pos_can_move[imay] < pos_n_move[inot]) {
			imay++;
			continue;
		}
		if (pos_can_move[jmay] > pos_n_move[jnot]) {
			jmay--;
			continue;
		}
		if(pos_can_move[imay] > pos_n_move[inot+1]) {
			inot++;continue;
		}
	}
	cout << "NO" << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
