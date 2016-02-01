#include <iostream>

using namespace std;

int main()
{

	int l;
	int k;
	string x;
	int n;
	int ok;

	cin >> x;
	cin >> k;

	n = x.length();

	if(n % k != 0) {
		cout << "NO\n";
		return 0;
	}

	l = n / k;
	
	ok = 1;
	
	for (int j = 0; j < n - (l - 1) and ok; j = j + l) {

		for (int i = j, k = j + (l -1); i < k; i++, k--) {
			if(x[i] != x[k]) {
				cout << "NO\n";
				return 0;
			}

		}

	}


	cout << "YES\n";
}
		


