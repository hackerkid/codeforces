#include <iostream>
#include <queue>
using namespace std;
int main()
{

	int n;
	int x;
	int y;
	int count;
	int temp;

	count = 0;
	cin >> n;	
	priority_queue <int> q;
	cin >> x;

	for (int i = 0; i < n-1; i++) {
		cin >> y;
		q.push(y);
	}

	while(q.top() >= x) {
		temp = q.top();
		q.pop();
		temp--;
		count++;
		x++;
		q.push(temp);
	}

	cout << count << endl;


}

