#include <bits/stdc++.h>
using namespace std;
int n, m, t;
vector<pair<pair<int,int>,int>> vec;
bool ford(){
	vector<int> dist(n);
	for(int i = 0; i < n; i++)
		for(int e = 0; e < vec.size(); e++){
			if(dist[vec[e].first.first] + vec[e].second < dist[vec[e].first.second]){
				if(i == n - 1)
					return 1;
				dist[vec[e].first.second] = dist[vec[e].first.first] + vec[e].second;
			}
		}
	return 0;
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		vec.resize(m);
		for(int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d%d%d", &vec[i].first.first, &vec[i].first.second, &vec[i].second);
		}
		printf("%s\n", ford() ? "possible" : "not possible");
	}
	return 0;
}