#pragma warning (disable : 4996 4018)

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
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = (100000 + 9) * 5;
const double PI = atan(1) * 4;
int n, co[MAX];
long long sum;
long long mem[MAX][3];
bool vis[MAX][3];
vector<int> vec;

long long solve(int idx, int g, long long sm) {
	if (idx == n && g == 3 && !sm)
		return 1;
	if (idx == n || g == 3)
		return 0;
	if (vis[idx][g])
		return mem[idx][g];
	long long ret = 0;
	if (sm + vec[idx] == sum)
		ret += solve(idx + 1, g + 1, 0);
	ret += solve(idx + 1, g, sm + vec[idx]);
	vis[idx][g] = 1;
	return mem[idx][g] = ret;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vec[i]);
		sum += vec[i];
	}
	if (sum % 3)
		printf("0\n");
	else {
		sum /= 3;
		printf("%I64d\n", solve(0, 0, 0));
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}
