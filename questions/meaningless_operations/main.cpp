#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll
#define endl "\n"

void solution();
void setup();
map<int, int> ans = {
	{3, 1},
	{7, 1},
	{15, 5},
	{31, 1},
	{63, 21},
	{127, 1},
	{255, 85},
	{511, 73},
	{1023, 341},
	{2047, 89},
	{4095, 1365},
	{8191, 1},
	{16383, 5461},
	{32767, 4681},
	{65535, 21845},
	{131071, 1},
	{262143, 87381},
	{524287, 1},
	{1048575, 349525},
	{2097151, 299593},
	{4194303, 1398101},
	{8388607, 178481},
	{16777215, 5592405},
	{33554431, 1082401},
	{67108863, 22369621}
};
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		solution();
	}
	return 0;
}

void solution() {
	ll n;
	cin >> n;
	if (ans.count(n)) {
		cout << ans[n] << endl;
		return;
	}
	int maxBit = __lg(n);
	int temp = (1ll << (maxBit + 1ll)) - 1ll;
	cout << temp << endl;
}
