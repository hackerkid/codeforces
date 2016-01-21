#include <iostream>
#include <vector>

using namespace std;
int primes[1003];


int main()
{

	int n;
	vector <int> v;
	long long x;
	vector <int> ans;
	
	cin >> n;

	for (int i = 2; i <= 1000; i++) {
		if(primes[i] == 0) {
			v.push_back(i);
			for (int j = 2 * i; j <= 1000; j = j + i) {
				primes[j] = 1;
			}
		}
	}


	for (int i = 0; i < v.size() and v[i] <= n; i++) {
		x = v[i];
		while(x <= n) {
			ans.push_back(x);
			x = x * v[i];
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		if(i != ans.size() - 1) {
			cout << ans[i] << " ";
		}

		else {
			cout <<ans[i] << "\n";
		}

	}
	
}
	



