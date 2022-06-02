#include <iostream>
#include <algorithm> 
using namespace std;

int n, m, arr[100001],sum, ans, l, r = 10000*100000;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		l = max(l, arr[i]);
	}


	while (l <= r) {
		int  mid = (l + r) / 2;
		int cnt = 1, idx = 0;
		int  blue = 0;
		while (idx < n) {
			blue += arr[idx];
			if (blue > mid) {
				cnt++;
				blue = 0;
				continue;
			}
			idx++;
		}

		if (cnt > m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			ans = mid;
		}
	}

	cout << ans;
}