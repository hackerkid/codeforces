#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

	int gcd;
	int a[100006];

	int n;
	
	scanf("%d", &n);	
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
		while(a[i] % 2 == 0) {
			a[i] = a[i] / 2;
		}

		while(a[i] % 3 == 0) {
			a[i] = a[i] / 3;
		}
	}

	gcd = a[0];

	

	for (int i = 1; i < n; i++) {
		if(a[i] != a[0]) {
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");


}

