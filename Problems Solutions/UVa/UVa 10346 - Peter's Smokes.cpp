#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	while(cin >> n >> k){
		int ans = 0, pf = 0;
		while(n){
			ans += n;
			pf += n;
			n = pf / k;
			pf %= k;
		}
		cout << ans << '\n';
	}
	return 0;
}
