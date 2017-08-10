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

int n, dp[15][33000][10];
vector <string> gprice;

class ImageTraders {
	int getBit(int msk, int idx) {
		return (msk >> idx) & 1;
	}
	int setBit(int msk, int idx, int val) {
		if (val)
			return msk | (1 << idx);
		return msk & ~(1 << idx);
	}
	int solve(int nxt, int msk, int mx) {
		if (dp[nxt][msk][mx] != -1)
			return dp[nxt][msk][mx];
		int ret = 0;
		for (int i = 0; i < n; i++)
			if (gprice[nxt][i] - '0' >= mx && !getBit(msk, i)) {
				int nmsk = setBit(msk, i, 1);
				ret = max(ret, 1 + solve(i, nmsk, gprice[nxt][i] - '0'));
			}
		return dp[nxt][msk][mx] = ret;
	}
public:
	int maxOwners(vector <string> price) {
		n = price.size();
		gprice = price;
		memset(dp, -1, sizeof(dp));
		return 1 + solve(0, 1, 0);
	}
};
