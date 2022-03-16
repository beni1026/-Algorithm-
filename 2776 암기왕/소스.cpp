#include <iostream>
#include <algorithm> 
using namespace std;

int t, n, arr[1000001], m;
int binary_search(int l, int r, int num) {
    while (1) {
        if (l > r) return 0;
        int mid = (l + r) / 2;
        if (arr[mid] == num) {
            return 1;
        }
        if (arr[mid] > num) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> t;
    while (t > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cin >> m;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            cout << binary_search(0, n-1, num) << "\n";
        }
        t--;
    }

    
}
