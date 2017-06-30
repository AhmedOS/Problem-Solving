#include <iostream>
#include <sstream>
using namespace std;

int counter;
string line;

int main(){

	while (getline(cin, line)){

		counter = 0;
		bool ok = true;
		bool lastok = false;
		
		for (int i = 0; i < line.length(); i++){

			if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
				ok = true;
			else
				ok = false;

			if (ok == true && lastok == false)
				counter++;

			lastok = ok;

		}

		cout << counter << endl;
	}

	return 0;
}