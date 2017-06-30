#include <bits/stdc++.h>
using namespace std;
int n, des;
vector<int> cost;
vector<vector<int>> arr[109];
int solve(){
	vector<vector<int>> dist(100);
	for(int i = 0; i < 100; i++){
		dist[i].resize(n+1);
		if(i)
			for(int e = 1; e <= n; e++)
				dist[i][e] = 1 << 30;
	}
	pair<int, pair<int, int>> p = {0, {0, 0}};
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qu;
	qu.push(p);
	while(!qu.empty()){
		pair<int, pair<int, int>> tp = qu.top();
		qu.pop();
		if(tp.first > dist[tp.second.first][tp.second.second])
			continue;
		for(int i = 1; i <= n; i++)
			for(int e = 0; e < arr[tp.second.first][i].size(); e++){
				int val = tp.first + cost[i] * abs(tp.second.first - arr[tp.second.first][i][e]) + (tp.second.second == i || !tp.second.second ? 0 : 60);
				if(val < dist[arr[tp.second.first][i][e]][i]){
					dist[arr[tp.second.first][i][e]][i] = val;
					pair<int, pair<int, int>> ne = {val, {arr[tp.second.first][i][e], i}};
					qu.push(ne);
				}
			}
	}
	int mn = 1 << 30;
	for(int i = 1; i <= n; i++)
		mn = min(mn, dist[des][i]);
	return mn;
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	while(cin >> n >> des){
		for(int i = 0; i < 100; i++){
			arr[i].clear();
			arr[i].resize(n+1);
		}
		cost.resize(n+1);
		for(int i = 1; i <= n; i++)
			cin >> cost[i];
		cin.ignore();
		for(int i = 1; i <= n; i++){
			string str;
			getline(cin, str);
			stringstream ss;
			ss << str;
			int nm, prv = -1;
			while(ss >> nm){
				if(prv == -1){
					prv = nm;
					continue;
				}
				arr[prv][i].push_back(nm);
				arr[nm][i].push_back(prv);
				prv = nm;
			}
		}
		int ret = solve();
		if(ret == 1 << 30)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ret);
	}
	return 0;
}
