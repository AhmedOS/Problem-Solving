#include <bits/stdc++.h>
using namespace std;
int n, x;
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	while(cin >> n){
		vector<int> vec(n);
		for(int i = 0; i < n; i++)
			cin >> vec[i];
		cin >> x;
		int ansa = 0, ansb = 1 << 30;
		sort(vec.begin(), vec.end());
		for(int i = 0; i < n; i++){
			int b = x - vec[i];
			auto it = upper_bound(vec.begin(), vec.end(), b);
			it--;
			if(it != vec.end() && *it == b && it - vec.begin() != i && abs(vec[i] - b) < abs(ansa - ansb)){
				ansa = vec[i];
				ansb = b;
			}
		}
		cout << "Peter should buy books whose prices are " << ansa << " and " << ansb << ".\n\n";
	}
	return 0;
}
