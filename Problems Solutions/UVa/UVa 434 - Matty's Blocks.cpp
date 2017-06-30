#include <iostream>
#include <algorithm>
using namespace std;

int k, front[10], rightt[10], fdub[10], rdub[10], fcounter, rcounter, maxk;

int max(){
	int max = 0;
	for (int s = 1; s <= maxk; s++){
		for (int d = 1; d <= maxk; d++){
			max += min(front[s], rightt[d]);
		}
	}
	return max;
}

int dub(int min){
	if (fcounter > rcounter){
		for (int i = 1; i <= maxk; i++){
			if (fdub[i] != 0 || rdub[i] != 0){
				for (int e = 1; e <= rdub[i] - fdub[i]; e++){
					min = min + i;
				}
			}
		}
	}
	else
	{
		for (int i = 1; i <= maxk; i++){
			if (fdub[i] != 0 || rdub[i] != 0){
				for (int e = 1; e <= fdub[i] - rdub[i]; e++){
					min = min + i;
				}
			}
		}
	}
	return min;
}

int miin(){
	int min = 0;

	if (fcounter > rcounter){
		for (int s = 1; s <= maxk; s++){
			min = min + front[s];
		}
	}
	else
	{
		for (int s = 1; s <= maxk; s++){
			min = min + rightt[s];
		}
	}

	min = dub(min);
	return min;
}


int main(){
	int t;

	cin >> t;
	for (int i = 1; i <= t; i++){
		fcounter = 0, rcounter = 0;

		for (int e = 1; e <= 10; e++){
			front[e] = 0;
		}
		for (int e = 1; e <= 10; e++){
			rightt[e] = 0;
		}
		for (int e = 1; e <= 10; e++){
			fdub[e] = 0;
		}
		for (int e = 1; e <= 10; e++){
			rdub[e] = 0;
		}

		cin >> k;
		maxk = k;

		for (int s = 1; s <= k; s++){
			cin >> front[s];
			fdub[front[s]]++;
			fcounter = fcounter + front[s];
			if (front[s] > maxk)
				maxk = front[s];
		}

		for (int s = 1; s <= k; s++){
			cin >> rightt[s];
			rdub[rightt[s]]++;
			rcounter = rcounter + rightt[s];
			if (rightt[s] > maxk)
				maxk = rightt[s];
		}

		int miiin = miin();
		int maax = max() - miiin;

		cout << "Matty needs at least " << miiin << " blocks, and can add at most " << maax << " extra blocks." << endl;

	}

	return 0;
}