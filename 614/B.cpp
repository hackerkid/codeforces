#include <iostream>

using namespace std;

int zero;

long long check(string x)
{
	
	if((x.length() == 1) and (x[0] == '0')) {
		zero = 1;
		return 0;
	}
	// valid cases with zeroes
	for (int i = x.length() - 1; i >= 1; i--) {
		if(x[i] != '0') {
			return -1;
		}

	}
	
	if(x[0] != '1') {
		return -1;
	}
	return x.length() - 1;

}

	

int main()
{
	
	int n;
	zero = 0;

	string  x;
	cin >> n;

	long long count = 0;
	long long temp;
	string good;
	good = "1";	
	for (int i = 0; i < n; i++) {
		cin >> x;
		if((temp = check(x)) != -1) {
			count += temp;
		}
		else {
			good = x;
		}
		


	}
	
	if(zero) {
		cout << 0 << "\n";
		return 0;
	}
	cout << good;

	for (int i = 0; i < count; i++) {
		cout << 0;
	}

	cout << "\n";


}