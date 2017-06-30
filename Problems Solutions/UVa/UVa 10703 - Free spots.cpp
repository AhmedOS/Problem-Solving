#include <iostream>
using namespace std;

int main(){

	int w, h, n, x1, y1, x2, y2, arr[500][500], emptyspots;

	while (cin >> w >> h >> n && w && h){

			emptyspots = h*w;

			for (int i = 0; i < n; i++){
				cin >> x1 >> y1 >> x2 >> y2;
				
				if (x2 < x1) {
					int temp = x1;
					x1 = x2;
					x2 = temp;
				}
				if (y2 < y1) {
					int temp = y1;
					y1 = y2;
					y2 = temp;
				}

				for (int a = x1; a <= x2; a++){
					for (int b = y1; b <= y2; b++){
						arr[a-1][b-1] = 1;
					}
				}
			}

			for (int s = 0; s < w; s++){
				for (int d = 0; d < h; d++){
					if (arr[s][d] == 1){
						emptyspots--;
						arr[s][d] = 0;
					}
				}
			}

			if (emptyspots > 1)
				cout << "There are " << emptyspots << " empty spots." << endl;
			else if (emptyspots == 1)
				cout << "There is one empty spot." << endl;
			else
				cout << "There is no empty spots." << endl;
		
	}
	return 0;
}