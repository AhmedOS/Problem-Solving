#include <iostream>
using namespace std;

int g, p, score[101][101], scoreorg[101][101], sys[101], k, sum[101];

int clear(char loop){
	int big;

	if (g > p)
		big = g;
	else
		big = p;

	if (loop == 'c'){
		for (int s = 1; s <= big; s++){
			for (int d = 1; d <= big; d++){
				score[s][d] = 0;
			}
		}
	}
	else if (loop == 'y'){
		for (int s = 1; s <= big; s++){
			sys[s] = 0;
		}
	}
	else if (loop == 'u'){
		for (int s = 1; s <= big; s++){
			sum[s] = 0;
		}
	}
	else if (loop == 'a'){
		for (int s = 1; s <= big; s++){
			for (int d = 1; d <= big; d++){
				score[s][d] = 0;
			}
		}
		for (int s = 1; s <= big; s++){
			sys[s] = 0;
		}
		for (int s = 1; s <= big; s++){
			sum[s] = 0;
		}
	}

	return 0;
}

int compare(){
	int max = 0;
	for (int s = 1; s <= p; s++){
		if (sum[s] > max)
			max = sum[s];
	}

	bool flag = false;
	for (int s = 1; s <= p; s++){
		if (sum[s] == max){
			if (flag)
				cout << " ";
			cout << s;
			flag = true;
		}
	}
	cout << endl;

	return 0;
}

int sumP(){
	int big;

	if (g > p)
		big = g;
	else
		big = p;

	for (int s = 1; s <= big; s++){
		for (int d = 1; d <= big; d++){
			sum[s] += score[d][s];
		}
	}

	return 0;
}

int PtoP(){

	for (int s = 1; s <= g; s++){
		for (int d = 1; d <= p; d++){
			bool flag = false;
			for (int i = 1; i <= k; i++){
				if (score[s][d] == i){
					score[s][d] = sys[i];
					flag = true;
					break;
				}
			}
			if (!flag)
				score[s][d] = 0;
		}
	}

	return 0;
}

int GetSetOriginal(char option){

	if (option == 'g')
	{
		for (int s = 1; s <= g; s++){
			for (int d = 1; d <= p; d++){
				scoreorg[s][d] = score[s][d];
			}
		}
	}
	else if (option == 's')
	{
		for (int s = 1; s <= g; s++){
			for (int d = 1; d <= p; d++){
				score[s][d] = scoreorg[s][d];
			}
		}
	}

	return 0;
}

int main(){
	int sysnum;
	
	while (cin >> g >> p && g && p){

		for (int s = 1; s <= g; s++){
			for (int d = 1; d <= p; d++){
				cin >> score[s][d];
			}
		}

		cin >> sysnum;
		for (int s = 1; s <= sysnum; s++){
			cin >> k;
			for (int d = 1; d <= k; d++){
				cin >> sys[d];
			}
			GetSetOriginal('g');
			PtoP();
			sumP();
			compare();
			clear('y');
			clear('u');
			GetSetOriginal('s');
		}

		clear('a');

	}

	return 0;
}