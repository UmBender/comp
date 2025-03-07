// #include <atcoder/all>
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
#define int ll
// using mint = atcoder::modint;

void solution() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int nn = n, nm = m;
  int k = 0;
  int down = 0;
  int up = 0;
  int neutral = 0;
  while (nn > nm && nn && nm) {
    k++;
    down++;
    nn -= 2;
    nm--;
  }
  while (nm > nn && nn && nm) {
    k++;
    up++;
    nm -= 2;
    nn--;
  }
  while (nm >= 3 && nn >= 3 && nn && nm) {
    k += 2;
    up++;
    down++;
    nm -= 3;
    nn -= 3;
  }
  if (min(nm, nn) == 1 && max(nm, nn) >= 2) {
    if (nm == 1) {
      down++;
    } else {
      up++;
    }
    k++;
  } else {
    if (min(nm, nn) == 2) {
      neutral++;
      k++;
    }
  }
  vector<int> as;
  vector<int> bs;
  int in = 0, jn = n - 1;
  int im = 0, jm = m - 1;
	for(int i = 1; i <= n; i++) {
		as.push_back(a[n-i] - a[i -1]);
	}
	for(int i = 1; i <= m; i++) {
		bs.push_back(b[m-i] - b[i -1]);
	}
  nn = n, nm = m;

	vector<int> ans;


  vector<int> pref_as(as.size()+1,0);
  vector<int> pref_bs(bs.size()+1,0);
  for(int i = 1; i < pref_as.size() ;i++){
    pref_as[i] = pref_as[i-1] + as[i-1];
  }
  for(int i = 1; i < pref_bs.size(); i++) {
    pref_bs[i]= pref_bs[i-1] + bs[i-1];
  }

	for(int k = 1; 3 * k <= n + m; k++) {
		int x_left = max(0LL, 2LL * k - m);
		int x_right = min(k, n - k);
		function<int(int)> get_sum = [&](int pos) {
			return pref_as[pos] + pref_bs[k - pos];
		};
		if(x_left > x_right) 
			break;
		while(x_right-x_left  > 3) {
			int ml=(x_left*2+x_right)/3, mr=(x_left+x_right*2)/3;
			if(get_sum(ml) > get_sum(mr)) {
				x_right = mr;
			}else{
				x_left = ml;
			}
		}
		ll mans = 0;
		for(int j = x_left; j<= x_right;j++){
			mans = max(mans,get_sum(j));
		}
		ans.push_back(mans);
	}


  if (ans.empty()) {
    cout << 0 << endl;
    return;
  }

  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i] << " \n"[i == k - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
