#include <iostream>
#include <stdio.h>
using namespace std;

enum consts {N = 100000};

int a[N + 5];
int b[N + 5];

int main()
{

	int n;
	int l;
	int r;
	int p;
	int count;
	double sum;

	sum = 0;

	cin >> n;
	cin >> p;

	for (int i = 0; i < n; i++) {
		cin >> l;
		cin >> r;
		
		count = (r / p) - ((l - 1) / p);

		a[i] = count;
		b[i] = r - l + 1;
	}

	for (int i = 0; i < n; i++) {
		double x = (long double) (b[i] - a[i])   /   (long double) b[i];
		double y = (long double) (b[(i + 1) % n] - a[(i + 1) % n]) /   (long double) b[(i + 1) % n];
		double both_not = 1 - x * y;
		sum += both_not * 2000;
	}
	
	printf("%.7lf", sum);
}


