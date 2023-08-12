#include <iostream>
#include <vector>
using namespace std;

int n, j, ans;
int main() {
	cin >> n >> j;
	vector<pair<int, int>> jump;
	for (int i = 0; i < j; i++) {
		int a, b;
		cin >> a >> b;
		if(a<b) jump.push_back(make_pair(a, b));
	}


	int now = 0;
	while (now < n) {
		now += 6;
		for (int i = 0; i < jump.size(); i++) {
			if()
		}
	}

	return 0;
}