#include <iostream>
#include <algorithm> 

using namespace std;

bool chk[10001];
int main() {
	for (int i = 1; i <= 10000; i++) {
		int n = i;
		if (chk[n] == 1) continue;
		else {
			while (n <= 10000) {
				int num = n;
				while (true) {
					n += (num % 10);
					if (num < 10) break;
					num /= 10;
				}
				chk[n] = 1;
			}
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (chk[i] == 0) cout << i << "\n";
	}

}