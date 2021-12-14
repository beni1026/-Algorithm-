#include <iostream>
#include <algorithm> 
using namespace std;

int n, k, ans;
int a[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        while (k >= a[i]) {
            k -= a[i];
            ans++;
        }

    }


    cout << ans;

}
