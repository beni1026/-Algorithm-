#include <iostream>
#include <algorithm> 
using namespace std;

int n, m, arr[100001], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 1;
    int right = 10000*100000;
        
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 1;
        int money = mid;
        for (int i = 0; i < n; i++) {
            if (money - arr[i] >= 0) {
                money -= arr[i];
            }
            else {
                if (mid < arr[i]) {
                    cnt = 100001;
                    break;
                }
                else {
                    cnt++;
                    money = mid;
                    money -= arr[i];
                }          
            }
        }
        if (cnt > m) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            ans = mid;
        }
    }

    cout << ans;
}
