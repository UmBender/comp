#include<bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128;
using VI = vector<i32>;
using VVI = vector<VI>;
using PII = pair<i32,i32>;
using VII = vector<PII>;
using VVII = vector<VII>;

void solution();

i32 main() {
	cin.tie(0)->sync_with_stdio(0);
	solution();
	return 0;
}


void solution() {
	i32 n, q;
	cin >> n >> q;
	set<pair<i32, i32>> lr;
	i64 counter = 0;
	auto intersection = [](i32 l1, i32 r1, i32 l2, i32 r2) -> bool {
		if( l1 <= l2 && r2 <= r1) {
			return true;
		}
		if(l2 <= l1 && r1 <= r2) {
			return true;
		}
		if(l1 <= l2 && r1 <= r2) {
			return true;
		}
		if(l2 <= l1 && r2 <= r1) {
			return true;
		}
		return false;
	};
	auto ninterval = [](i32 l1, i32 r1, i32 l2, i32 r2) -> pair<i32,i32> {
		array<i32,4> ele = {l1,r1,l2,r2};
		sort(ele.begin(), ele.end());
		return {ele.front(), ele.back()};
	};
	for(i32 qq = 0; qq < q; qq++) {
		i32 l, r;
		cin >> l >> r;
		if(lr.empty()){ 
			lr.insert({l, r});
			counter+= r - l + 1;
			cout << n - counter << endl;
			continue;
		}
		auto next = lr.lower_bound({l ,0});
		if(next != lr.begin()) {
			auto before = next;
			before--;
			if(before-> second >= l) {
				next = before;
			}
		}
		i32 templ = l, tempr = r;
		while(next != lr.end() && next->first <= tempr) {
			templ = min(templ, next->first);
			tempr = max(tempr, next->second);
			counter -= (next->second - next->first + 1);
			auto old = next;
			next++;
			lr.erase(old);
		}

		lr.insert({templ, tempr});
		counter += tempr - templ + 1;
		cout << n - counter << '\n';

			
	}

}
