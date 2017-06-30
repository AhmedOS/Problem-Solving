#include <iostream>
#include <cmath>
using namespace std;

int n, arr[101][101], temp[101][101], mem[110000000];

int refresh(int ring){
	for (int s = ring; s <= (n - ring + 1); s++){
		for (int d = ring; d <= (n - ring + 1); d++){
			if (s == ring || d == ring || s == n - ring + 1 || d == n - ring + 1)
				arr[s][d] = temp[s][d];
		}
	}
	return 0;
}

int updown(int ring){
	for (int s = ring; s <= (n - ring + 1); s++){
		for (int d = ring; d <= (n - ring + 1); d++){
			if (s == ring || d == ring || s == n - ring + 1 || d == n - ring + 1)
				temp[n - s + 1][d] = arr[s][d];
		}
	}
	return 0;
}


int leftright(int ring){
	for (int s = ring; s <= (n - ring + 1); s++){
		for (int d = ring; d <= (n - ring + 1); d++){
			if (s == ring || d == ring || s == n - ring + 1 || d == n - ring + 1)
				temp[s][n - d + 1] = arr[s][d];
		}
	}
	return 0;
}


int diag(int ring){
	for (int s = ring; s <= (n - ring + 1); s++){
		for (int d = ring; d <= (n - ring + 1); d++){
			if (s == ring || d == ring || s == n - ring + 1 || d == n - ring + 1)
				temp[d][s] = arr[s][d];
		}
	}
	return 0;
}


int indiag(int ring){
	for (int s = ring; s <= (n - ring + 1); s++){
		for (int d = ring; d <= (n - ring + 1); d++){
			if (s == ring || d == ring || s == n - ring + 1 || d == n - ring + 1)
				temp[n - d + 1][n - s + 1] = arr[s][d];
		}
	}
	return 0;
}


int main(){
	int m, t, c, lastpos = 0;

	cin >> m;
	for (int i = 1; i <= m; i++){

		cin >> n;
		for (int s = 1; s <= n; s++){
			for (int d = 1; d <= n; d++){
				cin >> arr[s][d];
			}
		}

		for (int ring = 1; ring <= round(n / 2.0); ring++){

			cin >> t;
			for (int q = 1; q <= t; q++){

				cin >> c;
				if (c == 1)
					updown(ring);
				else if (c == 2)
					leftright(ring);
				else if (c == 3)
					diag(ring);
				else if (c == 4)
					indiag(ring);

				refresh(ring);
			}
		}

		lastpos++;
		mem[lastpos] = n;

		for (int s = 1; s <= n; s++){
			for (int d = 1; d <= n; d++){
				lastpos++;
				mem[lastpos] = arr[s][d];
			}
		}


	}

	lastpos = 1;
	for (int i = 1; i <= m; i++){
		int info = mem[lastpos];
		lastpos++;
		int flag = 0;
		int counter = 0;
		for (int e = lastpos; e < lastpos + (info*info); e++){
			counter++;
			if (flag)
				cout << " ";
			cout << mem[e];
			flag = 1;
			if (counter == info){
				cout << endl;
				flag = 0;
				counter = 0;
			}
		}
		lastpos = lastpos + (info*info);
	}

	return 0;
}