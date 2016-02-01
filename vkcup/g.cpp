#include <bits/stdc++.h>
using namespace std;


bool cmp(pair <int, int> x, pair <int, int> y)
{
	return x.first + x.second > y.first + y.second;

}
int main()
{

	vector < pair <int, int > > maxi;
	vector < pair <int, int > > mini;

	int n;
	int m;
	int a;
	int b;
	int temp;
	int x, y;

	scanf("%d", &n);
	scanf("%d", &m);

	scanf("%d", &x);
	scanf("%d", &x);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		scanf("%d", &y);

		maxi.push_back(make_pair(x, y));

	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		scanf("%d", &y);

		mini.push_back(make_pair(x, y));

	}

//	sort(maxi.begin(), maxi.end(), cmp);
//	sort(mini.begin(), mini.end(), cmp);
	
	for (int i = 0; i < n; i++) {
		a = maxi[i].first;
		b = maxi[i].second;
		temp = 0;

		for (int j = 0;  j < m; j++) {
			if(mini[j].first > a and mini[j].second > b) {
				temp = 1;
				break;
			}

		}

		if(temp == 0) {
			printf("Max\n");
			return 0;
		}

	}


	printf("Min\n");
	return 0;

	

}



