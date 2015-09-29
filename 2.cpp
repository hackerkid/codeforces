#include <iostream>
#define SIZE 100005
using namespace std;

int a[SIZE];
int b[SIZE];

int main()
{


	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	for (int i = n-2; i >= 0; i--) {
		b[i] = max(b[i], b[i+1]);
	}

	for (int i = 0; i < n; i++) {
		if(a[i] <= b[i+1]) {
			cout << b[i+1] - a[i] + 1 << " ";
		}

		else {
			cout << 0 <<  " ";
		}
	}

	cout << "\n";

}
