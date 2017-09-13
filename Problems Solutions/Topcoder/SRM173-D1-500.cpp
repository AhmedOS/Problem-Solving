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

vector <string> island, instructions;
int tr, tc, lr, lc;
int dirr[] = { 1, -1, 0, 0 };
int dirc[] = { 0, 0, 1, -1 };
class TreasureHunt {
	bool water(int r, int c) {
		if (r < 0 || r == island.size() || c < 0 || c == island[0].size())
			return 1;
		return island[r][c] == '.';
	}
	bool beach(int r, int c) {
		if (!r || r == island.size() - 1 || !c || c == island[0].size() - 1)
			return 1;
		bool ok = 0;
		for (int i = 0; !ok && i < 4; i++)
			ok = island[r + dirr[i]][c + dirc[i]] == '.';
		return ok;
	}
	double solve(int r, int c) {
		for (int i = 0; i < instructions.size(); i++) {
			int val, am = instructions[i][2] - '0';
			if (instructions[i][0] == 'N')
				val = 1;
			else if (instructions[i][0] == 'S')
				val = 0;
			else if (instructions[i][0] == 'W')
				val = 3;
			else
				val = 2;
			while (am--) {
				r += dirr[val];
				c += dirc[val];
				if (water(r, c))
					return 1 << 30;
			}
		}
		lr = r;
		lc = c;
		return sqrt((r - tr) * (r - tr) + (c - tc) * (c - tc));
	}
public:
	vector <int> findTreasure(vector <string> island, vector <string> instructions) {
		::island = island;
		::instructions = instructions;
		for (int i = 0; i < island.size(); i++)
			for (int e = 0; e < island[i].size(); e++)
				if (island[i][e] == 'X') {
					tr = i;
					tc = e;
				}
		double mn = 1 << 30;
		int r = -1, c = -1;
		for (int i = 0; i < island.size(); i++)
			for (int e = 0; e < island[i].size(); e++)
				if (!water(i, e) && beach(i, e)) {
					double ret = solve(i, e);
					if (ret < mn) {
						mn = ret;
						r = i;
						c = e;
					}
				}
		vector<int> vec;
		if (r != -1) {
			solve(r, c);
			vec.push_back(lc);
			vec.push_back(lr);
		}
		return vec;
	}
};
