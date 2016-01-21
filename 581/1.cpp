#include <iostream>
using namespace std;

int main()
{

	int x;
	int y;
	int ans1;
	int ans2;


	cin >> x;
	cin >> y;

	ans1 = min(x, y);

	ans2 = max(x, y) - min(x, y);
	ans2 = ans2 / 2;

	cout << ans1 << " " <<ans2 << endl;

}

