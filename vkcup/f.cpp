#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int dp[1000006];
int arr[1000006];
int main()
{
	vector <int> primes;
	for (int i = 2; i <= 1000005; i++) {
		if(a[i] == 0) {
			primes.push_back(i);
			for (int j = 2 * i; j <= 1000005; j= j + i) {
				a[j] = 1;
			}

		}

	}

	int n;
	int maxi = -1;
	int x, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x] = 1;
	}

	for (int i = 0; i <= 1000000; i++) {
		
		if(arr[i]) {
			dp[i] = 1;
			for (int j = 0; j < primes.size() and i >= primes[j]; j++) {
				t = primes[j];
				
				while(arr[i / t] == 0 and i % t == 0 and i / t > 0) {
					t = t * 2;
				}

				if((i / t) > 0 and i % t == 0 and arr[i / t]) {
					dp[i] = max(dp[i / t] + 1, dp[i]);
					

				}

			}

		}

		maxi = max(maxi, dp[i]);

		


	}

	printf("%d\n", maxi);


}


	
