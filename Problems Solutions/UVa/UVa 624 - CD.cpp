#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int t, n, sum;
vector<int> vec, tmp, ans;

void solve(int idx, int sm){
	if(sm <= t && sm > sum){
		ans = tmp;
		sum = sm;
	}
	if(idx == n)
		return;
	tmp.push_back(vec[idx]);
	solve(idx + 1, sm + vec[idx]);
	tmp.pop_back();
	solve(idx + 1, sm);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	while(cin >> t){
		sum = 0;
		tmp.clear();
		ans.clear();
		cin >> n;
		vec.resize(n);
		for(int i = 0; i < n; i++)
			cin >> vec[i];
		solve(0, 0);
		int i = 0;
		for(; i < ans.size(); i++){
			if(i)
				cout << ' ';
			cout << ans[i];
		}
		if(i)
			cout << ' ';
		cout << "sum:" << sum << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}