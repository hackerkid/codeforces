#include <iostream>
#include <math.h>

using namespace std;

int main()
{

	long long x;
	long long ans;
	cin >> x;

	if(x / 5 == 0) {
		cout << 1 << "\n";
		return 0;
	}

	ans = ceil(x / 5.0);

	cout << ans << "\n";

}

	
