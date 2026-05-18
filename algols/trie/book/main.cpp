#include <iostream>
#include <vector>

using namespace std;
using i32 = int;
using i64 = long long;
using namespace std;
#define int i64
#define endl '\n'

constexpr int K = 26;
constexpr int N = 1000;

int trie[N][K];
bool match[N];

int actualNode = 0;

void addString(string &s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v][c] == -1) {
            trie[v][c] = actualNode++;
        }
        v = trie[v][c];
    }
    match[v] = true;
}

bool query(string &s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v][c] == -1) {
            return false;
        }
        v = trie[v][c];
    }
    return match[v];
}

signed main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            trie[i][j] = -1;
        }
    }

    vector<string> vs = {"pudim", "de", "leite"};
    for (auto i: vs) {
        addString(i);
    }
    vs.push_back("asdf");

    for (auto i: vs) {
        cout << query(i) << endl;
    }

    return 0;
}
