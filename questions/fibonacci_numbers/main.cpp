#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
constexpr int MOD = 1e9 + 7;

struct Matrix {
	int a[2][2];
};

Matrix operator*(Matrix& a, Matrix& b) {
	Matrix result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.a[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				result.a[i][j] += a.a[i][k] * b.a[k][j] % MOD;
				result.a[i][j] %= MOD;

			}
		}
	}
	return result;
}

Matrix id() {
	Matrix t;
	int n = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			t.a[i][j] = i == j ? 1 : 0;
		}
	}
	return t;
}

Matrix base() {
	Matrix t;
	t.a[0][0] = 1;
	t.a[0][1] = 1;
	t.a[1][0] = 1;
	t.a[1][1] = 0;
	return t;
}

Matrix fastExp(Matrix val, int power) {
	if (power == 0) {
		return id();
	}
	Matrix temp = val;
	Matrix p = fastExp(val, power / 2);
	temp = p * p;
	if (power & 1) {
		temp = temp * val;
	}
	return temp;
}

void show(Matrix a) {
	int n = 2;
	for (int i = 0; i < n; i++) {
		cout << "[";
		cout << a.a[i][0] << " " << a.a[i][1];
		cout << "]" << endl;
	}
}

int calc(int power) {
	if (power == 0) {
		return 0;
	}
	if (power == 1) {
		return 1;
	}
	auto result = fastExp(base(), power);
	return result.a[0][1];
}


signed main() {
	int n;
	cin >> n;
	cout << calc(n) << endl;
	return 0;
}
