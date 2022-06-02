#include <iostream>
#include <algorithm> 
using namespace std;


int n, arr[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;

    for (int i = 2; i < n + 1; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
    }

    cout << arr[n];

}
