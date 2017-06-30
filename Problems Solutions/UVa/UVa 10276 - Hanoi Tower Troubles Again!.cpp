#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int t, n;
vector<vector<int>> vec;

bool add(int nxt, int nm){
	if(nxt == n)
		return 0;
	int val = (vec[nxt].size() ? *vec[nxt].rbegin() : 0) + nm;
	int ro = ceil(sqrt(val));
	if(!vec[nxt].size() ||  ro * ro == val){
		vec[nxt].push_back(nm);
		return 1;
	}
	return add(nxt + 1, nm);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	cin >> t;
	while(t--){
		vec.clear();
		cin >> n;
		vec.resize(n);
		int i = 1;
		for(; add(0, i); i++);
		cout << i - 1 << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}