#include <bits/stdc++.h>
using namespace std;
int n, id, src, des;
map<string, int> mp;
vector<vector<int>> vec;
vector<string> strs;
vector<pair<int,int>> route;
int solve() {
	vector<bool> vis(strs.size());
	vector<pair<int,int>> p = { {-1, src} };
	queue<vector<pair<int,int>>> qu;
	qu.push(p);
	while (!qu.empty()) {
		vector<pair<int,int>> f = qu.front();
		qu.pop();
		if (f[f.size()-1].second == des){
			route = f;
			return 1;
		}
		if (vis[f[f.size()-1].second])
			continue;
		vis[f[f.size()-1].second] = 1;
		for (int i = 0; i < vec[f[f.size()-1].second].size(); i++){
			vector<pair<int,int>> nv;
			nv = f;
			nv.push_back({f[f.size()-1].second, vec[f[f.size()-1].second][i]});
			qu.push(nv);
		}
	}
	return -1;
}
void chk(string ss){
	int idx = mp[ss];
	if(!idx){
		mp[ss] = id++;
		strs.push_back(ss);
		vec.push_back({});
	}
}
int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	int t = 0;
	while(cin >> n){
		if(t++)
			cout << '\n';
		id = 1;
		mp.clear();
		route.clear();
		strs.clear();
		strs.push_back("");
		vec.clear();
		vec.push_back({});
		for(int i = 1; i <= n; i++){
			string a, b;
			cin >> a >> b;
			chk(a);
			chk(b);
			int ai = mp[a], bi = mp[b];
			vec[ai].push_back(bi);
			vec[bi].push_back(ai);
		}
		string aa, bb;
		cin >> aa >> bb;
		chk(aa);
		chk(bb);
		src = mp[aa];
		des = mp[bb];
		int ret = solve();
		if(ret != -1){
			for(int i = 1; i < route.size(); i++)
				cout << strs[route[i].first] << ' ' << strs[route[i].second] << '\n';
		}
		else
			cout << "No route\n";
	}
	return 0;
}
