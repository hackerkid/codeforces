#include <iostream>
#include <limits.h>
using namespace std;

int main()
{

	bool a[550][550];
	int n;
	int m;
	int q;
	int maxi;
	int p;
	int r;
	int total;

	cin >> n;
	cin >> m;
	cin >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int cs = 1; cs <= q; cs++) {
		cin >> p;
		cin >> r;

		p--;
		r--;

		a[p][r] = (a[p][r] + 1) % 2;

		maxi = INT_MIN;

		for (int i = 0; i < n; i++) {
			total = 0;
			for (int j = 0; j < m; j++) {
				if(a[i][j] == 1) {
					total += 1;
				}

				else {
					maxi = max(maxi, total);
					total = 0;
				}

			}

			maxi = max(maxi, total);

		}

		cout << maxi << endl;
	}
}


