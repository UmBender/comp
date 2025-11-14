#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) 
		solution();

	return 0;
}

void solution() {
    string s;
    cin >> s;
    if(s == "*") {
        cout << 1 << endl;
        return;
    }
    int n = s.size();
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '*' && s[i + 1] == '*') {
            cout << -1 << endl;
            return;
        }
        if(s[i] == '>' && s[i + 1] == '<') {
            cout << -1 << endl;
            return;
        }
        if(s[i] == '>' && s[i + 1] == '*') {
            cout << -1 << endl;
            return;
        }
        if(s[i] == '*' && s[i + 1] == '<') {
            cout << -1 << endl;
            return;
        }
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    if(s.front() == '>' && s.back() == '<') {
        cout << -1 << endl;
        return;
    }
    int first = 0;
    for(int i = 0; i <n;i ++){
        if(s[i] == '>'){
            break;
        }
        first++;
    }
    int second = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '<') {
            break;
        }
        second ++;
    }
    cout << max(first, second) << endl;
}
