#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int n, k, arr[30001], cnt[30001], ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++) {
        cnt[i] = arr[i + 1] - arr[i];
    }

    sort(cnt, cnt + n - 1);

    for (int i = 0; i < k - 1; i++) {
        ans += cnt[i];
    }

    cout << ans;

   
}
