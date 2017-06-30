#include <bits/stdc++.h>
using namespace std;
int n, src, des;
vector<string> vec;
vector<int> cost, path;
map<string, int> mp;
vector<pair<int,int>> arr[29];
struct edge{
	int from, to, cost;
	bool operator<(const edge &a) const {
		if (a.cost < cost)
			return 1;
		return 0;
	}
};
int solve(){
	path.clear();
	vector<int> dist(n, 1 << 30), prv(n);
	prv[src] = -1;
	dist[src] = cost[src];
	priority_queue<edge> qu;
	edge e = {-1, src, cost[src]};
	qu.push(e);
	while(!qu.empty()){
		edge tp = qu.top();
		qu.pop();
		if(tp.cost > dist[tp.to])
			continue;
		prv[tp.to] = tp.from;
		for(int i = 0; i < arr[tp.to].size(); i++){
			if(arr[tp.to][i].second + tp.cost + cost[arr[tp.to][i].first] < dist[arr[tp.to][i].first]){
				dist[arr[tp.to][i].first] = arr[tp.to][i].second + tp.cost + cost[arr[tp.to][i].first];
				edge ed = {tp.to, arr[tp.to][i].first, arr[tp.to][i].second + tp.cost + cost[arr[tp.to][i].first]};
				qu.push(ed);
			}
		}
	}
	int pr = des;
	do{
		path.push_back(pr);
		pr = prv[pr];
	}while(pr != -1);
	return dist[des];
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for(int t = 1; t <= tt; t++){
		if(t != 1)
			cout << '\n';
		printf("Map #%d\n", t);
		scanf("%d", &n);
		mp.clear();
		vec.resize(n);
		cost.resize(n);
		for(int i = 0; i < n; i++){
			cin >> vec[i] >> cost[i];
			mp[vec[i]] = i;
			arr[i].clear();
		}
		int tmp;
		scanf("%d", &tmp);
		for(int i = 0; i < tmp; i++){
			string a, b;
			int co;
			cin >> a >> b >> co;
			co *= 2;
			arr[mp[a]].push_back({mp[b], co});
			arr[mp[b]].push_back({mp[a], co});
		}
		int q;
		scanf("%d", &q);
		for (int qc = 1; qc <= q; qc++){
			string a, b;
			int am;
			cin >> a >> b >> am;
			src = mp[a];
			des = mp[b];
			int ret = solve();
			double tot = ret + ret * 10 / 100.0;
			printf("Query #%d\n", qc);
			for(int i = path.size() - 1; i >= 0; i--){
				if(i != path.size() - 1)
					cout << ' ';
				cout << vec[path[i]];
			}
			cout << '\n';
			printf("Each passenger has to pay : %.2lf taka\n", tot / am);
		}
	}
	return 0;
}
