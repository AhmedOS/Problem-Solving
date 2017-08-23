#include <bits/stdc++.h>
using namespace std;
int n, tc = 1;
vector<pair<double,double>> vec;
bool eq(double a, double b){
	return abs(a - b) < 1e-9;
}
bool ok(double gap){
	double cur = vec[0].first + gap;
	for(int i = 1; i < n; i++)
		if(cur > vec[i].second && !eq(cur, vec[i].second))
			return 0;
		else if(cur < vec[i].first || eq(cur, vec[i].first))
			cur = vec[i].first + gap;
		else
			cur += gap;
	return 1;
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	while(cin >> n && n){
		vec.resize(n);
		for(int i = 0; i < n; i++){
			cin >> vec[i].first >> vec[i].second;
			vec[i].first *= 60;
			vec[i].second *= 60;
		}
		sort(vec.begin(), vec.end());
		double mx = 0;
		do{
			double s = 0, e = 86400, ans = 0;
			while(e - s >= 1e-3){
				double mid = (s + e) / 2;
				if(ok(mid)){
					ans = mid;
					s = mid;
				}
				else
					e = mid;
			}
			mx = max(mx, ans);
		}while(next_permutation(vec.begin(), vec.end()));
		int fmx = round(mx);
		cout << "Case " << tc << ": " << (fmx / 60) << ':' << setfill('0') << setw(2) << (fmx % 60) << '\n';
		tc++;
	}
	return 0;
}
