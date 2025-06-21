// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <utility>
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

struct Node {
	Node *last_node;
	ll value;
	~Node() {}
};

void solution() {
	ll n, q;
	cin >> n >> q;
	vector<tuple<ll, ll, string>> queries(q);
	for (auto &[t, p, s] : queries) {
		cin >> t;
		if (t == 1 || t == 3) {
			cin >> p;
			p--;
		} else {
			cin >> p >> s;
			p--;
		}
	}
	vector<string> n_string = {""};

	vector<Node *> nodes;

	nodes.push_back(new Node{
	    .last_node = nullptr,
	    .value = -1,
	});
	Node *actual_node = nodes[0];
	vector<Node *> last_nodes(n, actual_node);
	for (auto &[t, p, s] : queries) {
		if (t == 1) {
			last_nodes[p] = actual_node;
			continue;
		}
		if (t == 2) {
			n_string.push_back(s);
			Node *new_node = new Node{};

			new_node->last_node = last_nodes[p];
			new_node->value = n_string.size() - 1;
			nodes.push_back(new_node);
			last_nodes[p] = new_node;
		};
		if (t == 3) { actual_node = last_nodes[p]; }
	}
	string acc = "";
	vector<ll> parts;
	while (actual_node->value != -1) {
		parts.push_back(actual_node->value);
		actual_node = actual_node->last_node;
	}
	reverse(parts.begin(), parts.end());
	for (ll i : parts) { acc += n_string[i]; }
	cout << acc << endl;
	for (auto i : nodes) { delete i; }
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
