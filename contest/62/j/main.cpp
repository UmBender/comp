// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;
// clang-format on

set<int> def_set = {1, 2, 3, 4, 5, 6, 7, 8, 9};
set<int> intersec(set<int> &first, set<int> &second, set<int> &third) {
    set<int> sol;
    for (int i = 1; i <= 9; i++) {
        if (first.count(i) && second.count(i) && third.count(i)) {
            sol.insert(i);
        }
    }
    return sol;
}

set<int> joins(set<int> &first, set<int> &second) {
    set<int> pudim;
    for (int i : first) {
        if (second.count(i)) {
            pudim.insert(i);
        }
    }
    return pudim;
}

void solution() {
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (auto &i : sudoku) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    vector<vector<set<int>>> sub(3, vector<set<int>>(3, def_set));
    vector<set<int>>         columns(9, def_set);
    vector<set<int>>         lines(9, def_set);
    vector<vector<set<int>>> wsub(3, vector<set<int>>(3));
    vector<set<int>>         wcolumns(9);
    vector<set<int>>         wlines(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] != 0) {
                if (sub[i / 3][j / 3].count(sudoku[i][j])) {
                    sub[i / 3][j / 3].erase(sudoku[i][j]);
                    wsub[i / 3][j / 3].insert(sudoku[i][j]);
                }
                if (columns[j].count(sudoku[i][j])) {
                    columns[j].erase(sudoku[i][j]);
                    wcolumns[j].insert(sudoku[i][j]);
                }
                if (lines[i].count(sudoku[i][j])) {
                    lines[i].erase(sudoku[i][j]);
                    wlines[i].insert(sudoku[i][j]);
                }
            }
        }
    }
    int  iter      = 0;
    bool is_solved = false;
    while (iter < 1000) {
        bool solved = true;
        bool finded = false;
        int  whol, whoc;
        for (int i = 0; i < 9 && !finded; i++) {
            for (int j = 0; j < 9 && !finded; j++) {
                if (sudoku[i][j] == 0) {
                    set<int> inter =
                        intersec(sub[i / 3][j / 3], columns[j], lines[i]);
                    if (inter.size() != 0) {
                        solved = false;
                    }
                    if (inter.size() == 1) {
                        sudoku[i][j] = *inter.begin();
                        sub[i / 3][j / 3].erase(*inter.begin());
                        wsub[i / 3][j / 3].insert(*inter.begin());
                        columns[j].erase(*inter.begin());
                        wcolumns[j].insert(*inter.begin());
                        lines[i].erase(*inter.begin());
                        wlines[i].insert(*inter.begin());
                        finded = true;
                        whol   = i;
                        whoc   = j;
                    }
                    if (!finded) {
                        int      bl        = i - (i % 3);
                        int      br        = j - (j % 3);
                        set<int> intersect = def_set;
                        for (int k = bl; k < bl + 3; k++) {
                            if (k != i) {
                                intersect = joins(intersect, wlines[k]);
                            }
                        }
                        for (int k = br; k < br + 3; k++) {
                            if (k != j) {
                                intersect = joins(intersect, wcolumns[k]);
                            }
                        }
                        if (intersect.size() == 1 &&
                            inter.count(*intersect.begin())) {
                            sudoku[i][j] = *intersect.begin();
                            sub[i / 3][j / 3].erase(*intersect.begin());
                            wsub[i / 3][j / 3].insert(*intersect.begin());
                            columns[j].erase(*intersect.begin());
                            wcolumns[j].insert(*intersect.begin());
                            lines[i].erase(*intersect.begin());
                            wlines[i].insert(*intersect.begin());
                            finded = true;
                            whol   = i;
                            whoc   = j;
                        }
                    }
                }
            }
        }

        if (solved) {
            is_solved = true;
        }
        iter++;
    }
    if (is_solved) {
        cout << "Easy" << endl;
    } else {
        cout << "Not easy" << endl;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                cout << '.' << " \n"[j == 8];
            } else {
                cout << sudoku[i][j] << " \n"[j == 8];
            }
        }
    }
    // l = 2,c = 3;
    set<int> pi = intersec(sub[0][0], columns[2], lines[1]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
