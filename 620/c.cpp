#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;


int main()
{

	int n;
	int a[300005];
	int left;

	map <int, bool> mp;

	scanf("%d", &n);
	
	vector < pair <int, int> > vec;
	left = 1;

	for (int i  = 1; i <= n; i++) {
		if(mp.find(a[i]) != mp.end()) {
			vec.push_back(make_pair(left, i));
			left = i + 1;
			mp.clear();
		}
		else {
			mp[a[i]] = true;
		}
	}

	if(vec.size() > 0 and vec[vec.size() - 1].second != n) {
		vec[vec.size() - 1].second = n;
	}

	if(vec.size() != 0) {
		printf("%d\n", vec.size());
		for (int i = 0; i < vec.size(); i++) {
			printf("%d %d\n", vec[i].first, vec[i].second);
		}
	}
	else {
		printf("-1\n");
	}

	return 0;

	
}
