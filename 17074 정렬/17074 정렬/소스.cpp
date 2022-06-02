#include <iostream>
#include <algorithm> 
using namespace std;

int n, arr[100002], m, cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    m = arr[0];
    for (int i = 1; i < n; i++) {
        if (m >= arr[i]) cnt++;
        m = min(m, arr[i]);
    }

    cout << m + 1;

}
