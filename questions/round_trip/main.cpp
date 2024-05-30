#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

vector<int> path;
void print() {
	for(auto i: path) {
		cout << i << " ";
	}
	cout << endl;
}

int dfs(vector<vector<int>> &roads, vector<int> &who_acessed, int actual_pos) {
	for(int next_node: roads[actual_pos]) {
		if(who_acessed[next_node] == -1 && actual_pos == 0) {
			continue;
		}
		if(who_acessed[next_node] == -1 || who_acessed[next_node] == -2) {
			path.push_back(next_node);
			who_acessed[next_node] = actual_pos;
			int stat = dfs(roads,who_acessed,next_node);
			if(stat == 1) {
				return 1;
			}
			who_acessed[next_node] = -1;
			path.pop_back();
			continue;
		}
		if(who_acessed[actual_pos] == next_node) {
			continue;
		}
		path.push_back(next_node);
		return 1;
	}

	return 0;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int ncities, nroads;
  cin >> ncities >> nroads;
  vector<vector<int>> roads(ncities+1);
  vector<int> who_acessed(ncities+1, -2);

  for (int i = 0; i < nroads; i++) {
    int first, second;
    cin >> first >> second;
    roads[first].push_back(second);
    roads[second].push_back(first);
		roads[0].push_back(second);
		roads[0].push_back(first);
  }
	roads[0].push_back(1);

  path.push_back(0);
  int stats = dfs(roads, who_acessed, 0);
  if (stats == 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  int round = path[path.size() - 1];
  vector<int> true_path;
  true_path.push_back(round);
  for (int i = path.size() - 2; i > 0; i--) {
    true_path.push_back(path[i]);
    if (path[i] == round) {
      break;
    }
  }
  cout << true_path.size() << endl;
  for (auto i : true_path) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
