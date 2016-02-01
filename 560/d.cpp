#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


char x[200005];
char y[200005];


int check(int i, int j, int ii, int jj)
{

	if(j - i != jj - ii) {
		return 0;
	}
	for (int k = i, kk = ii; k <= j; k++, kk++) {
		if(x[k] != y[kk]) {
			return 0;
		}

	}

	return 1;

}
int explore(int i, int j, int ii, int jj)
{

	
	if(i > j or ii > jj) {
		return 0;
	}

	if(check(i, j, ii, jj)) {
		return 1;
	}

	if(((j - i) + 1) % 2 == 1 or ((jj - ii) + 1) % 2 == 1) {
		return 0;
	}

	if((j - i == 0) or (jj - ii == 0)) {
		return 0;
	}

	return (explore(i, (i+j)/2, ii, (ii+jj)/ 2) and explore((i+j)/2+1, j, (ii+ jj)/2+1, jj)) or (explore(i, (j+i)/2, (ii+jj)/2 + 1, jj) and explore( (i + j) / 2 + 1,j, ii, (jj + ii)/2));
}





int main()
{

	cin >> x;
	cin >> y;

	if(explore(0, strlen(x) - 1, 0, strlen(y) -1)) {
//		printf("YES\n");
		cout << "YES\n";
	}

	else {
		cout << "NO\n";
	}


	

}
