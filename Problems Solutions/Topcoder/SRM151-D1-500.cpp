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

class MergeSort {
	pair<vector<int>, int> merge(vector<int> a, vector<int> b) {
		vector<int> ve(a.size() + b.size());
		int ret = 0;
		int i = 0, e = 0, g = 0;
		while (i < a.size() && e < b.size()) {
			if (a[i] < b[e]) {
				ve[g] = a[i];
				i++;
			}
			else if (a[i] > b[e]) {
				ve[g] = b[e];
				e++;
			}
			else {
				ve[g] = a[i];
				i++;
				g++;
				ve[g] = b[e];
				e++;
			}
			ret++;
			g++;
		}
		while (i < a.size()) {
			ve[g] = a[i];
			i++;
			g++;
		}
		while (e < b.size()) {
			ve[g] = b[e];
			e++;
			g++;
		}
		return make_pair(ve, ret);
	}
	pair<vector<int>, int> solve(vector<int> v) {
		if (v.size() <= 1)
			return make_pair(v, 0);
		vector<int> b(v.size() / 2), c(v.size() - v.size() / 2);
		for (int i = 0; i < v.size() / 2; i++)
			b[i] = v[i];
		for (int i = 0; i < v.size() - v.size() / 2; i++)
			c[i] = v[i + v.size() / 2];
		pair<vector<int>, int> sb = solve(b);
		pair<vector<int>, int> sc = solve(c);
		int sum = sb.second + sc.second;
		pair<vector<int>, int> ret = merge(sb.first, sc.first);
		ret.second += sum;
		return ret;
	}
public:
	int howManyComparisons(vector <int> numbers) {
		return solve(numbers).second;
	}
};
