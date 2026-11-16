#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    vector<pair<char, int>> qq(q);
    map<int, char> chs;
    for (int i = 0; i < q; i++) {
        cin >> qq[i].first;
        qq[i].second = i;
        if (qq[i].first == 'I') { cin >> chs[i]; }
    }
    vector<pair<char, int>> sp;
    for (int i = 0; i < q; i++) {
        if (qq[i].first == 'U' && !sp.empty()) {
            sp.pop_back();
            continue;
        }
        sp.push_back(qq[i]);
    }
    string left, right;
    for (int i = 0; i < sp.size(); i++) {
		if (sp[i].first == 'I') {
			left.push_back(chs[sp[i].second]);
		}
		if (sp[i].first == 'L' && !left.empty()) {
			right.push_back(left.back());
			left.pop_back();
		}
		if (sp[i].first == 'R' && !right.empty()) {
			left.push_back(right.back());
			right.pop_back();
		}
		if (sp[i].first == 'B' && !left.empty()) {
			left.pop_back();
		}
	}
	int pos = left.size();
	while (!right.empty()) {
		left.push_back(right.back());
		right.pop_back();
	}
	if (left.empty()) {
		cout << "_" << endl;
		cout << pos << endl;
		return 0;
	}
	cout << left << endl;
	cout << pos << endl;

    return 0;
}
