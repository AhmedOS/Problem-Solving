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

int dp[51];
class InsertSort {
public:
	vector<int> theArray;
	int calcMinimalCost(vector <int> theArray) {
		int bst = 0;
		for (int i = 0; i < theArray.size(); i++) {
			int mx = 0;
			for (int e = i - 1; e >= 0; e--)
				if (theArray[e] <= theArray[i] && dp[e] > mx)
					mx = dp[e];
			dp[i] = mx + theArray[i];
			bst = max(bst, dp[i]);
		}
		int ret = 0;
		for (int i = 0; i < theArray.size(); i++)
			ret += theArray[i];
		return ret - bst;
	}
};
