#include <bits/stdc++.h>
using namespace std;
int t, n, m, q, src, des;
struct edge {
	int from, to, time, dist;
	bool operator<(const edge &a) const {
		return a.time < time;
	}
};
vector<vector<edge>> arr;
pair<int,int> solve(){
	vector<pair<int,int>> dist(n+1, {1 << 30, 1 << 30});
	dist[src] = {0,0};
	priority_queue<edge> qu;
	edge e = {-1, src, 0, 0};
	qu.push(e);
	while(!qu.empty()){
		edge tp = qu.top();
		qu.pop();
		if(tp.time > dist[tp.to].first || (tp.time == dist[tp.to].first && tp.dist > dist[tp.to].second))
			continue;
		for(int i = 0; i < arr[tp.to].size(); i++){
			if(tp.time + arr[tp.to][i].time < dist[arr[tp.to][i].to].first
			|| (tp.time + arr[tp.to][i].time == dist[arr[tp.to][i].to].first && tp.dist + arr[tp.to][i].dist < dist[arr[tp.to][i].to].second)){
				dist[arr[tp.to][i].to].first = tp.time + arr[tp.to][i].time;
				dist[arr[tp.to][i].to].second = tp.dist + arr[tp.to][i].dist;
				edge ne = {tp.to, arr[tp.to][i].to, tp.time + arr[tp.to][i].time, tp.dist + arr[tp.to][i].dist};
				qu.push(ne);
			}
		}
	}
	return dist[des];
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	cin >> t;
	while(t--){
		cin >> n >> m;
		arr.resize(n+1);
		for(int i = 0; i < m; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			edge e = {a, b, c, d};
			arr[a].push_back(e);
			e.from = b;
			e.to = a;
			arr[b].push_back(e);
		}
		cin >> q;
		while(q--){
			cin >> src >> des;
			pair<int, int> ret = solve();
			if(ret.first == (1 << 30))
				printf("No Path.\n");
			else
				printf("Distance and time to reach destination is %d & %d.\n", ret.second, ret.first);
		}
		if(t){
			cout << '\n';
			arr.clear();
		}
	}
	return 0;
}
