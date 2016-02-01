#include <iostream>
#include <map>
using namespace std;

enum consts { N = 1000};

map <int, int> mp1;
map <int, int> mp2;

int update(int x, int y)
{

	mp1[x + y]++;
	mp2[x - y]++;
}

long long cal(int x)
{
	return ((x - 1) * x) / 2; 
}

int main()
{

	int n;
	int x;
	int y;
	long long sum;

	sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> y;
		update(x, y);
	}

	for (map <int, int>::iterator it = mp1.begin(); it != mp1.end(); it++) {
		sum += cal(it->second);
	}

	for (map <int, int>::iterator it = mp2.begin(); it != mp2.end(); it++) {
		sum += cal(it->second);
	}

	cout << sum << endl;


}