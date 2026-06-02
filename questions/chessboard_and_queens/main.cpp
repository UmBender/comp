#include <bits/stdc++.h>
#include <functional>
#include <pthread.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    array<string, 8> grid;
    for (auto &i : grid) {
        cin >> i;
    }
    int acc = 0;
    vector<bool> column(8);
    set<int> pri, sec;
    vector<int> state(8, -1);
    function<void(int line)> dfs = [&](int line = 0) {
        if (line == 8) {
            acc++;
            return;
        }
        for (int col = 0; col < 8; col++) {
            if (grid[line][col] == '*') {
                continue;
            }

            int sum = line + col;
            int diff = line - col;
            if (!pri.count(sum) && !sec.count(diff) && !column[col]) {
                pri.insert(sum);
                sec.insert(diff);
                column[col] = true;
                dfs(line + 1);
                pri.erase(sum);
                sec.erase(diff);
                column[col] = false;
            }

        }
    };
    dfs(0);
    cout << acc << endl;
    return 0;
}
