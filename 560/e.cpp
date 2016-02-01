#include <iostream>
#include <string.h>
#include <map>
using namespace std;


int n;
int m;

int ans[5000][5000];
long long mod = (1e9 + 7);

map <pair <int, int>, int > q;
map <pair <int, int>, int > ans;

long long explore(int i, int j)
{
	long long x;
	long long y;
	
	x = y = 0;
	
	if(i == n - 1 and j == m - 1) {
		return 1;
	}

	if(ans.count(make_pair(i, j))) {
			return ans[make_pair(i, j)];
	}
		


	if(i + 1 < n and (q.count(make_pair(i + 1, j)) == 1)) {
		x = explore(i+1, j);
	}

	if(j+1 < m and (q.count(make_pair(i, j+1)) == 1)) {
		y = explore(i, j+1);
	}
	
	return ans[make_pair(i, j)] = (x+y) % mod;

	

}




int main()
{
	memset(ans, -1, sizeof(ans));

	int b;
	int i;
	int j;
	long long ans;

	cin >> n;
	cin >> m;
	cin >> b;

	for (int cs = 1; cs <= b; cs++) {
		cin >> i >> j;
		q[make_pair(i-1, j-1 )] = 1;
	}

	ans = explore(0, 0);

}

