#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <limits.h>
using namespace std;

int count[4005];
bool a[4005][4005];
int x;

int main()
{

	int n;
	int m;
	int y;
	int z;
	int ans;
	int sum;

	memset(a, 0, sizeof a);
	memset(count, 0, sizeof count);
	
	ans = INT_MAX;

	cin >> n;
	cin >> m;
	
	vector < pair <int, int> > v;
	
	for (int i = 0; i < m; i++) {
		cin >> x;
		cin >> y;
		a[x][y] = 1;
		a[y][x] = 1;
		count[y]++;
		count[x]++;
		
		v.push_back(make_pair(x, y));

	}

	for (int i = 0; i < m; i++) {
		x = v[i].first;
		y = v[i].second;

		for (int j = 1; j <= n; j++) {
			if(a[x][j] and a[y][j]) {
				sum = count[x] + count[y] + count[j] - 6;
				ans = min(ans, sum);
			}

		}

	}


	if(ans == INT_MAX) {
		cout << -1 <<  endl;
	}

	else {
		cout << ans << endl;
	}

}

