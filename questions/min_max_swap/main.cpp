#include <bits/stdc++.h>
#include <vector>

using namespace std;
struct Gen{
	vector<int>v1;
	vector<int>v2;
	int size;

};


int get_max(vector<int>&ref) {
	int max = 0;
	for(int i = 0; i < (int)ref.size(); i ++) {
		if(max < ref[i]) {
			max = ref[i];
		}

	}
	return max;

}

int main(int argc, char** argv)
{
	int t = 0;
	cin >> t;
	vector<Gen> obj;
	for(int i =0; i < t; i++) {
		Gen op;
		cin >> op.size;
		for(int j = 0; j < op.size; j++) {
			int n;
			cin >> n;
			op.v1.push_back(n);
		}
		for(int j = 0; j < op.size; j++) {
			int n;
			cin >> n;
			op.v2.push_back(n);
		}
		obj.push_back(op);
	}
	for(int i = 0; i < t; i++) {
		for(int j = 0; j < obj[i].size; j++) {
			if(obj[i].v1[j] < obj[i].v2[j]) {
				int temp = obj[i].v1[j] ;
				obj[i].v1[j] =   obj[i].v2[j];
				obj[i].v2[j] = temp;
			}
		}
		int max1 = get_max(obj[i].v1);
		int max2 = get_max(obj[i].v2);
		cout << max1 * max2 << endl;
	}



	return 0;
}
