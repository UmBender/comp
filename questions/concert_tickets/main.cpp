#include <bits/stdc++.h>
#include <climits>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solve(vector<int> &tickets, vector<int> &customer, int N, int M) {

  map<int, int> pendingTickets;
  for (int i = 0; i < N; i++) {
    pendingTickets[tickets[i]] += 1;
  }

	for(int i = 0; i < M; i++) {
		auto it = pendingTickets.upper_bound(customer[i]);
		if(it == pendingTickets.begin()) {
			cout << -1 << endl;
		}else{
			it--;
			cout << it->first << "\n";
			it->second -= 1;
			if (it->second == 0)
				pendingTickets.erase(it);
		}

	}

}

int32_t main() {

  int N = 5, M = 3;
  cin >> N >> M;
  vector<int> tickets;
  vector<int> customer;

  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    tickets.push_back(val);
  }
  for (int i = 0; i < M; i++) {
    int val;
    cin >> val;
    customer.push_back(val);
  }
  solve(tickets, customer, N, M);

  return 0;
}
