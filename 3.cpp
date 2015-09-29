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

		ans += round((double) a[i] / double (10));

		if(x != 0) {
			q.push(5 - x);
		}
	}

	cout << ans << endl;	

	while(m and q.size() != 0) {
		x = q.top();
		q.pop();
		if(x > m) {
			break;
		}

		else {
			m = m - x;
			ans++;
		}

	}

	cout << ans << endl;


}

