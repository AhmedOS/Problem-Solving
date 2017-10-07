#pragma warning (disable : 4996 4018)

//#include <thread>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

string arr[] = {
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqr",
	"stu",
	"vwx",
	"yz",
	".,!",
	" "
};
map<char, int> cost;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 11; i++)
		for (int e = 0; e < arr[i].size(); e++)
			cost[arr[i][e]] = e + 1;
	string s;
	getline(cin, s);
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		ans += cost[s[i]];
	cout << ans << '\n';
	return 0;
}
