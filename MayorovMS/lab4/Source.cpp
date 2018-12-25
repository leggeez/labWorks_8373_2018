#include <iostream>
#include <conio.h>
using namespace std;

float deg (float n, int deg2) {
	bool cursor = false;
	float x = n;
	if (deg2 != 0) {
		if (deg2 < 0) {
			deg2 = -deg2;
			cursor = true;
		}
		if (deg2 != 1) {
			for (int i = 1; i < deg2; i++) {
				x = x*n;
			}
		}
	}
	else {
		x = 1;
	}
	if (cursor) {
		x = 1 / x;
	}
	return x;
}

int fact (int n) {
	int x = 1;
	int i = 1;
	if ((n != 0) && (n != 1)) {
		while (i != n) {
			x = x*(i + 1);
			i++;
		}
	}
	return x;
}

double sqrt(double num)
{
	if (num == 0) {
		return num;
	}
	double m;
	double x = num / 2;
	do
	{
		m = x;
		x = (m + (num / m)) / 2;
	} while ((m - x) != 0);
	return x;
}

int simple (int n) {
	int i;
	for ( i = 2; i < n; i++) {
		if ( n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	float n;
	int deg2;
	int f, k, l;
	cout << "Enter number: " << endl;
	cin >> n;
	cout << "Enter degree: " << endl;
	cin >> deg2;
	cout << "Result:" << deg(n, deg2) << endl;
	cout << "Enter fact: " << endl;
	cin >> f;
	cout << "Result:" << fact(f) << endl;
	cout << "Enter sqrt: " << endl;;
	cin >> k;
	if (k < 0) {
		cout << "the radical of a negative number does not exist" << endl;
	}
	else {
		cout << "Result:" << sqrt(k) << endl;
	}
	cout << "Enter simple: " << endl;;
	cin >> l;
	if (simple(l)){
		cout << "Result: number " << l << " is simple" << endl;
	}
	else {
		cout << "Result: number " << l << " isn't simple" << endl;
	}
	_getch();
	return 0;
}
