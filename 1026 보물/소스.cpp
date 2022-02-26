#include <iostream>
#include <algorithm> 
using namespace std;

int n, ans;
int arr1[101], arr2[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2 + n, greater<>());

    for (int i = 0; i < n; i++) {
        ans += arr1[i] * arr2[i];
    }

    cout << ans;
}
