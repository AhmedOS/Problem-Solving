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

string str = "";
int dp[2501][2501];
class PalindromePartition {
	bool ispal(int s, int e) {
		bool pal = 1;
		int sz = e - s + 1;
		for (int i = 0; pal && i < sz / 2; i++)
			pal = str[s + i] == str[e - i];
		return pal;
	}
	int solve(int s, int e) {
		if (dp[s][e] != -1)
			return dp[s][e];
		if (e == str.size()) {
			if (s == e)
				return 0;
			e--;
			if (ispal(s, e))
				return 1;
			return e - s + 1;
		}
		int ret = solve(s, e + 1);
		if (ispal(s, e))
			ret = min(ret, 1 + solve(e + 1, e + 1));
		return dp[s][e] = ret;
	}
public:
	int partition(vector <string> s) {
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < s.size(); i++)
			str += s[i];
		return solve(0, 0);
	}
};
