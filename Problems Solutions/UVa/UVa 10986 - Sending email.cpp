#include <bits/stdc++.h>
using namespace std;
int t, n, m, src, des;
vector<vector<pair<int,int>>> vec;
int solve(){
	vector<int> dist(n, 1 << 30);
	dist[src] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu;
	qu.push({0, src});
	while(!qu.empty()){
		pair<int,int> tp = qu.top();
		qu.pop();
		if(tp.first > dist[tp.second])
			continue;
		for(int i = 0; i < vec[tp.second].size(); i++){
			if(tp.first + vec[tp.second][i].second < dist[vec[tp.second][i].first]){
				dist[vec[tp.second][i].first] = tp.first + vec[tp.second][i].second;
				qu.push({tp.first + vec[tp.second][i].second, vec[tp.second][i].first});
			}
		}
	}
	return dist[des];
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> n >> m >> src >> des;
		vec.clear();
		vec.resize(n);
		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			vec[a].push_back({b, c});
			vec[b].push_back({a, c});
		}
		int ret = solve();
		if(ret == 1 << 30)
			printf("Case #%d: unreachable\n", tc);
		else
			printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}
