#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (n == 2) {
        cout << "1 1" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "0" << endl;
        return 0;
    }

    queue<int> nodes;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            nodes.push(i);
        }
    }
    vector<int> dp_sub(n + 1, -1);
    vector<int> dp_ext(n + 1, -1);
    vector<int> counter(n + 1);
    for (int i = 1; i <= n; i++) {
        counter[i] = adj[i].size();
    }

    int last = 0;
    while (!nodes.empty()) {
        int actual = nodes.front();
        nodes.pop();
        dp_sub[actual] = 0;
        for (int next : adj[actual]) {
            if (dp_sub[next] == -1) {
                counter[next]--;

                if (counter[next] <= 1) {
                    nodes.push(next);
                }
                continue;
            }
            dp_sub[actual] = max(dp_sub[actual], dp_sub[next] + 1);
        }
        last = actual;
    }

    priority_queue<pair<int, int>> next_nodes;
    for (auto next : adj[last]) {
        next_nodes.push({dp_sub[next], next});
    }
    int biggest = next_nodes.top().first + 1;
    int biggest_node = next_nodes.top().second;
    next_nodes.pop();
    int second = next_nodes.top().first + 1;
    int second_node = next_nodes.top().second;
    dp_ext[last] = biggest;
    for (auto next : adj[last]) {
        if (next == biggest_node) {
            dp_ext[next] = second + 1;
            nodes.push(next);
        } else {
            dp_ext[next] = biggest + 1;
            nodes.push(next);
        }
    }
    while (!nodes.empty()) {
        int actual = nodes.front();
        nodes.pop();
        for (auto next : adj[actual]) {
            if (dp_ext[next] != -1) {
                continue;
            }
            dp_ext[next] = dp_ext[actual] + 1;
            nodes.push(next);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp_ext[i] << " ";
    }
    cout << endl;
}
