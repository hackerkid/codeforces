
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
	
	int n;
	int m;
	int x;
	int ans;
	priority_queue <int, vector <int> , greater <int> > q;
	int a[100005];
	
	ans = 0;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x = a[i] % 10;

		ans += floor((double) a[i] / double (10));

		if(x != 100) {
			q.push(10 - x);
		}
	}


	while(m and q.size() != 0) {
		x = q.top();
		q.pop();
		if(x > m) {
			break;
		}

		else {
			m = m - x;
			q.push(10);
			ans++;
		}

	}

	cout << ans << endl;


}

