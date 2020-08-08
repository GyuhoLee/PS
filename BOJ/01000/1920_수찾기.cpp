#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr1[100000];
int arr2[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> arr2[i];
	sort(arr1, arr1 + N);
	for (int i = 0; i < M; i++) {
		if (binary_search(arr1, arr1 + N, arr2[i]))
			printf("1\n");
		else printf("0\n");
	}

	return 0;
}