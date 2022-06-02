#include <iostream>
#include <algorithm> 
using namespace std;

int n, arr[52];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = arr[0] * arr[n - 1];
    cout << ans;
    
}
