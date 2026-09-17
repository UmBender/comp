#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl '\n'

constexpr int MOD = 1e9 + 7;



vvi mat = {
	{1,1,1,1,1,1},
	{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
};

vi vet = {
	32,
	16,
	8,
	4,
	2,
	1
};




int32_t main() {
	int n;
	cin >> n;

	auto mult = [&](vvi first, vvi second) -> vvi {
		vvi base(first.size(), vi(first[0].size()));
		int n = first.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int acc = 0;
				for (int k = 0; k < n; k++) {
					int temp = first[i][k] * second[k][j];
					temp %= MOD;
					acc += temp;
					acc %= MOD;
				}
				base[i][j] = acc;
			}
		}
		return base;
	};

	auto getIden = [&](int n) -> vvi {
		vvi ans(n, vi(n));
		for (int i = 0; i < n; i++) ans[i][i] = 1;
		return ans;
	};

	auto fastExp = [&](vvi base, int exp) -> vvi {
		vvi ans = getIden(base.size());
		for (int i = 0; i < 64; i++) {
			if ((exp >> i) & 1) {
				ans = mult(base, ans);
			}
			base = mult(base, base);
		}	
		return ans;
	};


	if (n <= 6) {
		n--;
		cout << vet[5 - n] << endl;
		return 0;
	}		

	n-=6;

	vvi nmat = fastExp(mat, n);
	vi acc(vet.size());
	for (int i = 0; i < vet.size(); i++) {
		for (int j = 0; j < vet.size(); j++) {
			acc[i] += (nmat[i][j] * vet[j]) % MOD;
			acc[i] %= MOD;
		}
	}
	
	cout << acc[0] << endl;
	return 0;
}
