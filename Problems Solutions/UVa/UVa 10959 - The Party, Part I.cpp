#include <bits/stdc++.h>
using namespace std;
int t, n, m;
vector<vector<int>> vec;
void solve(){
	vector<int> dist(n, 1 << 30);
	dist[0] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu;
	qu.push({0, 0});
	while(!qu.empty()){
		pair<int,int> tp = qu.top();
		qu.pop();
		if(tp.first > dist[tp.second])
			continue;
		for(int i = 0; i < vec[tp.second].size(); i++){
			if(tp.first + 1 < dist[vec[tp.second][i]]){
				dist[vec[tp.second][i]] = tp.first + 1;
				qu.push({tp.first + 1, vec[tp.second][i]});
			}
		}
	}
	for(int i = 1; i < n; i++)
		cout << dist[i] << '\n';
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	cin >> t;
	while(t--){
		cin >> n >> m;
		vec.clear();
		vec.resize(n);
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		solve();
		if(t)
			cout << '\n';
	}
	return 0;
}
