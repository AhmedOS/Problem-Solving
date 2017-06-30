#include <bits/stdc++.h>
using namespace std;
int n;
char arr[4][4];
bool bad(int ro, int co){
	int oro = ro, oco = co;
	for(co--; co >= 0 && arr[ro][co] != 'X'; co--)
		if(arr[ro][co] == 'a')
			return 1;
	co = oco;
	for(co++; co < n && arr[ro][co] != 'X'; co++)
		if(arr[ro][co] == 'a')
			return 1;
	co = oco;
	for(ro--; ro >= 0 && arr[ro][co] != 'X'; ro--)
		if(arr[ro][co] == 'a')
			return 1;
	ro = oro;
	for(ro++; ro < n && arr[ro][co] != 'X'; ro++)
		if(arr[ro][co] == 'a')
			return 1;
	return 0;
}
int solve(int ro, int co){
	if(co == n){
		ro++;
		co = 0;
	}
	if(ro == n)
		return 0;
	int a = 0;
	if(arr[ro][co] == '.' && !bad(ro, co)){
		arr[ro][co] = 'a';
		a = 1 + solve(ro, co + 1);
		arr[ro][co] = '.';
	}
	return max(solve(ro, co + 1), a);
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	while(cin >> n && n){
		for(int i = 0; i < n; i++)
			for(int e = 0; e < n; e++)
				cin >> arr[i][e];
		cout << solve(0, 0) << '\n';
	}
	return 0;
}
