#pragma warning (disable : 4996)

#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 101;
int n, arr[MAX][MAX];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int e = 0; e < n; e++) {
			scanf("%d", &arr[i][e]);
			if (i)
				arr[i][e] += arr[i - 1][e];
			if (e)
				arr[i][e] += arr[i][e - 1];
			if (i && e)
				arr[i][e] -= arr[i - 1][e - 1];
		}

	int ans = -127 * 100 * 100;
	for (int i = 0; i < n; i++)
		for (int e = 0; e < n; e++)
			for (int w = i; w < n; w++)
				for (int s = e; s < n; s++) {
					int sub = arr[w][s];
					if (i)
						sub -= arr[i - 1][s];
					if (e)
						sub -= arr[w][e - 1];
					if (i && e)
						sub += arr[i - 1][e - 1];
					ans = max(ans, sub);
				}

	printf("%d\n", ans);

	return 0;
}