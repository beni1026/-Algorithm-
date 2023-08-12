#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;

int n, k, ans;
long long arr[30];
pair<int, int> p[30]; //공격력, 마을수
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first;
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i].second;
	}

	sort(p, p + n+1);


	for (int i = 1; i <= n; i++) {
		memset(arr, 0, 30 * sizeof(long long));
		long long sum = 0;
		int e = 1, num;
		while (true) {
			for (int x = i; x < e; x++) {
				sum += arr[x];
			}
			sum += p[e].first;
			arr[e] = sum;
			if (sum > k || e > n) {
				num = e - 1;
				break;
			}
			e++;
		}
		int ps = 0;
		for (int j = i; j <= num; j++) {
			ps += p[j].second;
		}
		ans = max(ans, ps);
	}

	cout << ans;

}
