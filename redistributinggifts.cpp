#include <iostream>
using namespace std;

int res(int x) {
	if (x == 1000000) return x;
	return res(x + 1);
}

int main() { cout << res(0) << "\n"; }
