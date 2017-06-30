#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int t, n, m;
bool vis[109];
vector<vector<int>> vec;
vector<int> ans;

void solve(int nxt){
	if(nxt > n){
		vector<int> tmp;
		for(int i = 1; i <= n; i++)
			if(vis[i])
				tmp.push_back(i);
		if(tmp.size() > ans.size())
			ans = tmp;
		return;
	}
	bool bl = 1;
	for(int i = 0; i < vec[nxt].size() && bl; i++)
		bl = !vis[vec[nxt][i]];
	if(bl){
		vis[nxt] = 1;
		solve(nxt + 1);
		vis[nxt] = 0;
	}
	solve(nxt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	cin >> t;
	while(t--){
		vec.clear();
		ans.clear();
		cin >> n >> m;
		vec.resize(n+1);
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		solve(1);
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++){
			if(i)
				cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}