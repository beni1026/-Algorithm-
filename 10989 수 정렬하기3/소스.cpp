#include <iostream>
#include <algorithm> 
using namespace std;
int n, arr[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << "\n";
        }
    }
}
