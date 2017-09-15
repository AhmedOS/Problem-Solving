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

int usv[1001], themv[1001];
class ChessMatchup {
public:
	int maximumScore(vector <int> us, vector <int> them) {
		int ans = 0;
		sort(us.begin(), us.end());
		sort(them.begin(), them.end());
		for (int i = 0; i < us.size(); i++) {
			vector<int>::iterator it = upper_bound(them.begin(), them.end(), us[i] - 1);
			if (it != them.begin()) {
				it--;
				them.erase(it);
				ans += 2;
				us[i] = 0;
			}
		}
		for (int i = 0; i < us.size(); i++)
			usv[us[i]]++;
		for (int i = 0; i < them.size(); i++)
			themv[them[i]]++;
		for (int i = 1; i <= 1000; i++)
			ans += min(usv[i], themv[i]);
		return ans;
	}
};
