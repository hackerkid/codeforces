#include <iostream>
#include <math.h>

using namespace std;

int main()
{

	unsigned long long l;
	unsigned long long r;
	unsigned long long k;
	unsigned long long start;
	unsigned long long pows;
	int ok;

	ok = 0;
	cin >> l;
	cin >> r;
	cin >> k;
	

	start = 1;	
	
	while(start <= r) {
		if(start >= l) {		
			cout << start << " ";
			ok = 1;
		}

		if(r / k < start) {
			break;
		}
		start = start * k;

	}

	if(ok == 0) {
		cout << "-1";
	}

	cout << "\n";
	
}


