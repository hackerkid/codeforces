#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n;
int tar;
long long a[20][20];
long long val[20];
int m;

long long dp[19][1 << 18];

#define check(n, pos) (n & (1<<pos))
#define set(n, pos) (n | (1<<pos))

long long dfs(int last, int mask)
{
	
	int x;
	int y;
	int w;
	long long ans;

	ans = 0;

	if(__builtin_popcount(mask) == m) {
		return 0;
	}

	if(dp[last][mask] != -1) {
		return dp[last][mask];
	}
	
	for (int i = 0; i < n; i++) {
		if(check(mask, i) == 0) {
			ans = max(ans, val[i] + a[last][i] + dfs(i, set(mask, i)));
		}

	}
	return dp[last][mask] = ans;

}

int main()
{

	int x;
	int y;
	int w;
	int c;
	
	cin >> n;
	cin >> m;
	cin >> c;

	memset(dp, -1, sizeof dp);

	for(int i = 0; i < n; i++) {
		cin >>  val[i];
	}

	for (int i = 0; i < c; i++) {
		cin >> x;
		cin >> y;
		cin >> w;
		a[x-1][y-1] = w;
	}
	
	cout << dfs(n, 0) << endl;

	return 0;	

}


