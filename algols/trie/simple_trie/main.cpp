#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

const int K = 26;
struct Vertex {
    int next[K];
    bool output = false;

    Vertex() { fill(begin(next), end(next), -1); }
};

vector<Vertex> trie(1);

void addString(string &s) {

    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }

        v = trie[v].next[c];
    }
    trie[v].output = true;
}

bool query(string &s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            return false;
        }
        v = trie[v].next[c];
    }
    return trie[v].output;
}

signed main() {
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
