#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int num = 0;
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			num += a;
		}
		if (num == 3) cout << "A\n";
		else if (num == 2) cout << "B\n";
		else if (num == 1) cout << "C\n";
		else if (num == 4) cout << "E\n";
		else cout << "D\n";
	}
}
