#include <iostream>
using namespace std;

int main()
{
	int t;
	char pl1, pl2;
	cin >> t;
	int* win = new int[t];
	if (t > 1000 && t < 0){

	}
	else{
		for (int a = 0; a < t; a++){
			int n;
			int winpl1 = 0, winpl2 = 0;
			cin >> n;
			for (int b = 1; b <= n; b++){
				cin >> pl1 >> pl2;
				switch (pl1){
				case 'R':if (pl2 == 'P'){
							 winpl2++;
				}
						 else if (pl2 == 'S'){
							 winpl1++;
						 }
						 break;

				case 'S':if (pl2 == 'R'){
							 winpl2++;
				}
						 else if (pl2 == 'P'){
						 winpl1++;
				}
						 break;
				
				case 'P':if (pl2 == 'S'){
							 winpl2++;
				}
						 else if (pl2 == 'R'){
							 winpl1++;
						 }
						 break;
				}

			}
			if (winpl1 > winpl2){
				win[a] = 1;
			}
			else if (winpl1 == pl2){
				win[a] = 3;
			}
			else if (winpl1 < winpl2){
				win[a] = 2;
			}
		}
		for (int c = 0; c < t; c++){
			if (win[c] == 1){
				cout << "Player 1" << endl;
			}
			else if (win[c] == 2){
				cout << "Player 2" << endl;
			}
			else {
				cout << "TIE" << endl;
			}
		}
	}
	return 0;
}