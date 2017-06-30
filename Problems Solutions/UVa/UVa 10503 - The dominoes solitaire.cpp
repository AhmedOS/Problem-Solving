#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int n, m, sl, sr, el, er;
vector<pair<int,int>> vec;
bool vis[19];

bool solve(int nxt, int prv){
	if(nxt == n)
		return prv == el;
	for(int i = 0; i < vec.size(); i++){
		if(vis[i])
			continue;
		if(vec[i].first == prv || vec[i].second == prv){
			vis[i] = 1;
			int ret = solve(nxt + 1, (vec[i].first == prv ? vec[i].second : vec[i].first));
			vis[i] = 0;
			if(ret)
				return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	while(cin >> n && n){
		vec.clear();
		cin >> m >> sl >> sr >> el >> er;
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			vec.push_back({a,b});
		}
		cout << (solve(0, sr) ? "YES" : "NO") << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}