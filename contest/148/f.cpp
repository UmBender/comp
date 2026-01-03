#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32, i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

const i64 MOD = 998244353;
i64 power(i64 base, i64 exp) {
    i64 res = 1;
    base %= MOD;
    while (exp > 0) { if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}


struct BIT {
    i32 n;
    vector<i32> tree;
    
    BIT(i32 n) : n(n), tree(n + 1, 0) {}
    
    void add(i32 pos, i32 delta) {
        for (; pos <= n; pos +=  pos & -pos) {
            tree[pos] += delta;
		}
		
    }
    
    i32 query(i32 right) {
        i32 sum = 0;
        for (; right > 0; right -= right & -right) {
            sum += tree[right];
		}
        return sum;
    }
};


i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	i32 n;
	cin >> n;
	vector<i64> p(n);
	for (i32 i = 0; i < n; i++) {
		cin >> p[i];
	}
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	}
    vector<i64> l(n);
    BIT left(n);
    for (i32 i = 0; i < n; i++) {
        l[i] = left.query(p[i]);
        left.add(p[i], 1);
    }

    vector<i64> r(n);
    BIT right(n);
    for (i32 i = n - 1; i >= 0; i--) {
        r[i] = right.query(p[i]);
        right.add(p[i], 1);
    }

    vector<i64> pow2(n + 1);
    vector<i64> inv2(n + 1);
    pow2[0] = 1;
    inv2[0] = 1;
    i64 inv2_val = (MOD + 1) / 2;
    
    for (i32 i = 1; i <= n; i++) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
        inv2[i] = (inv2[i-1] * inv2_val) % MOD;
    }

    i64 ans = 0;
    i64 current_sum_L = 0;

    for (i32 j = 0; j < n; j++) {
        i64 term_eq = (l[j] * r[j]) % MOD;
        ans = (ans + term_eq) % MOD;

        if (j > 0) {
            i64 term_less = (r[j] * pow2[j-1]) % MOD;
            term_less = (term_less * current_sum_L) % MOD;
            ans = (ans + term_less) % MOD;
        }

        i64 add_to_sum = (l[j] * inv2[j]) % MOD;
        current_sum_L = (current_sum_L + add_to_sum) % MOD;
    }

    cout << ans << "\n";

	return 0;
}

