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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
//using mint = atcoder::modint;
// clang-format on

struct State {
	int pen;
	vector<int> y;
	int last;
	bool operator>(const State &other) const { return pen > other.pen; }
};

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
    solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, k, x;
	cin >> n >> k >> x;

	vector<int> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }

	sort(a.rbegin(), a.rend());

	int mmax = 0;
	for (int i = 0; i < k; i++) { mmax += a[0]; }
	mmax = k * a[0];

	if (n == 1) {
		cout << mmax << endl;
		return;
	}

	vector<int> b(n - 1);
	for (int i = 0; i < n - 1; ++i) { b[i] = a[i] - a[i + 1]; }

	priority_queue<State, vector<State>, greater<State>> pq;

	pq.push({0, vector<int>(n - 1, 0), -1});

	int count = 0;
	while (!pq.empty() && count < x) {
		State curr = pq.top();
		pq.pop();

		cout << mmax - curr.pen << endl;
		count++;

		if (count == x) { break; }

		int indices[] = {curr.last, curr.last + 1};

		for (int i : indices) {
			if (i < 0 || i >= n - 1) { continue; }
			bool possible = false;
			if (i == 0) {
				if (curr.y[0] < k) { possible = true; }
			} else {
				if (curr.y[i] < curr.y[i - 1]) { possible = true; }
			}

			if (possible) {
				State next = curr;
				next.y[i]++;
				next.pen += b[i];
				next.last = max(curr.last, i);

				pq.push(next);
			}
		}
	}
}
