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

class TrueFalse {
	int q, all = 0;
	int getBit(int msk, int idx) {
		return (msk >> idx) & 1;
	}
	int setBit(int msk, int idx, int val) {
		if (val)
			return msk | (1 << idx);
		return msk & ~(1 << idx);
	}
	int dif(int a, int b) {
		int ret = 0;
		for (int i = 0; i < q; i++) {
			if ((a & 1) == (b & 1)) {
				ret++;
				all = setBit(all, i, 1);
			}
			a >>= 1;
			b >>= 1;
		}
		return ret;
	}
	long long power(long long nm, int pw) {
		if (!pw)
			return 1;
		long long rs = power(nm, pw / 2);
		return rs * rs * (pw & 1 ? nm : 1);
	}
public:
	string answerKey(vector <string> graded) {
		vector<pair<int, int>> vec(graded.size());
		for (int i = 0; i < graded.size(); i++) {
			int nm = 0, mo = 0, c = 0, msk = 0;
			for (int e = 0; e < graded[i].size(); e++) {
				if (mo) {
					msk = setBit(msk, c++, graded[i][e] == 'T');
				}
				else {
					if (graded[i][e] == ' ') {
						q = graded[i].size() - e - 1;
						mo = 1;
						continue;
					}
					nm *= 10;
					nm += graded[i][e] - '0';
				}
			}
			vec[i] = make_pair(nm, msk);
		}
		int mx = power(2, q);
		string ans = "";
		for (int i = 0; i < mx; i++) {
			all = 0;
			bool ok = 1;
			for (int e = 0; ok && e < vec.size(); e++)
				ok = dif(i, vec[e].second) == vec[e].first;
			if (ok && !dif(all, 0)) {
				string ret = "";
				int nm = i;
				for (int e = 0; e < q; e++) {
					ret += (nm & 1 ? 'T' : 'F');
					nm >>= 1;
				}
				if (!ans.size() || ret < ans)
					ans = ret;
			}
		}
		return (ans.size() ? ans : "inconsistent");
	}
};
