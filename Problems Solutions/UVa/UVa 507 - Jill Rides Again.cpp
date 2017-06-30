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

const int MAX = 20001;
int t, n, arr[MAX];

int main() {

	scanf("%d", &t);
	int c = t;
	while (c--) {

		scanf("%d", &n);
		n--;

		int sum = 0, mx = 0, ti = 0, ai = 0, aj = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
			if ((sum > mx) || ((sum == mx) && (i - ti > aj - ai))) {
				mx = sum;
				aj = i;
				ai = ti;
			}
			if (sum < 0) {
				sum = 0;
				ti = i + 1;
			}
		}

		if (mx <= 0)
			printf("Route %d has no nice parts\n", t - c);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", t - c, ai + 1, aj + 2);

	}

	return 0;
}