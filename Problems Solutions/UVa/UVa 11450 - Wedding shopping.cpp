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

const int MAX = 201;
const int MAX2 = 21;
int t, tm, n, ng[MAX2], pg[MAX2][MAX2];
bool can[MAX2][MAX];

int main() {

	scanf("%d", &t);
	while (t--) {

		scanf("%d%d", &tm, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ng[i]);
			for (int e = 0; e < ng[i]; e++)
				scanf("%d", &pg[i][e]);
		}


		for (int i = 0; i < ng[0]; i++)
			if (tm - pg[0][i] >= 0)
				can[0][tm - pg[0][i]] = 1;

		for (int i = 1; i < n; i++)
			for (int w = 0; w <= tm; w++)
				if (can[i - 1][w])
					for (int e = 0; e < ng[i]; e++)
						if (w - pg[i][e] >= 0)
							can[i][w - pg[i][e]] = 1;

		int i = 0;
		for (; i <= tm && !can[n - 1][i]; i++);


		if (i == tm + 1)
			printf("no solution\n");
		else
			printf("%d\n", tm - i);


		if (t)
			memset(can, 0, sizeof(can));

	}

	return 0;
}