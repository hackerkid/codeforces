#include <iostream>
#include <limits.h>
using namespace std;

int main()
{

	int t;
	int n;
	int mini;
	int x;

	mini = INT_MAX;

	long long sum;

	sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;

		if(x % 2)
			mini = min(mini, x);
	}

	if(sum % 2)
		sum = sum - mini;

	cout << sum << endl;

}
