#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;
#define int ll

void solution() {
	int n;
	cin >> n;
	map<string, int> sells;
	for(int i = 0; i < n; i++) {
		string name;
		int count;
		cin >> name >> count;
		sells[name] += count;
	}
	vector<pair<int,string>> list;
	list.reserve(sells.size());
	for(auto &[i,j]: sells) {
		list.push_back({j,i});
	}
	sort(list.begin(), list.end(), [](auto &i, auto &j) {
			if(i.first > j.first) {
				return true;
			}
			if(i.first < j.first) {
				return false;
			}
			return i.second < j.second;
			});
	cout << list.size() << endl;
	for(int i = 0 ; i < list.size() ;i++) {
		cout << list[i].second << " " << list[i].first << endl;
	}

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
