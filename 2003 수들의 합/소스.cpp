#include <iostream>
#include <algorithm> 
using namespace std;


int n, m, arr[10001], cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    while(left<n&&right<n) {
        int  ans = 0;
        for (int j = left; j <= right; j++) {
            ans += arr[j];
        }
        if (ans == m) {
            //cout << left << " " << right << endl;
            cnt++;
            right++;
        }
        else if (ans < m) {
            right++;
        }
        else {
            left++;
        }
    }

    cout << cnt;

}