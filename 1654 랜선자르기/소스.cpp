#include <iostream>
#include <algorithm> 
using namespace std;

long long k, n, arr[10001], l, r, ans;
void binary_search(long long arr[], long long n) {
    l = 1;
    r = arr[k - 1];
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += arr[i] / mid;
        }
        if (cnt < n) {
            r = mid - 1;
        }
        else {
            if (ans < mid) {
                ans = mid;
            }
            l = mid + 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + k);
    binary_search(arr, n);
    cout << ans;
}
