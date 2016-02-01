#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{

	long long int a[100005];
	vector < pair <int, int> 
	int n;
	long long maxi;

	maxi = INT_MIN;

	priority_queue <long long int> q; 
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; i++) {
		
		if(a[i] < a[i+1]) {
			q.push(a[i]);
			ans[i] = 1;
		}

		else {
			q.push(a[i+1]);
			ans[i+1] = 1;
		}

	}

	maxi = max(maxi, a[n-1]);
	
	if(q.top() != 
	q.push(maxi);
	
	int i = 0;

	while(i < n - 1) {
		cout << q.top() << " ";
		q.pop();
		i++;
	}

	cout << q.top() << endl;

}

