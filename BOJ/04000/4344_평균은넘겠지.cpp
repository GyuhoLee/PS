#include <iostream>
#include <cmath>
using namespace std;

double round(double values, int pos);

int main(){
	int size;
	cin >> size;
	
	double arr[1000];
	double arr2[1000];
	for (int i = 0; i < size; i++){
		double n;
		double sum = 0;
		double avg = 0;
		cin >> n;
		for (int j = 0; j < n; j++){
			double num;
			cin >> num;
			arr[j] = num;
			sum += num;
		}

		avg = sum / n;
		//avg = round(avg, 3);
		double count = 0;
		for (int j = 0; j < n; j++){
			if (arr[j] > avg){ 
				count++;
			}
		}

		double total;
		total= count / n * 100;
		total = round(total, 3);
		arr2[i] = total;		
	}

	for (int i = 0; i < size; i++){
		cout << fixed;
		cout.precision(3);
		cout << arr2[i] << "%" << endl;
	}
}

double round(double value, int pos)
{
	double temp;
	temp = value * pow(100, pos);  
	temp = floor(temp + 0.05);         
	temp *= pow(100, -pos);        
	return temp;
}

