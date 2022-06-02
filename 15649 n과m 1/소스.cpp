#include <iostream>
#include <algorithm> 
using namespace std;

int n, m, arr[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    do {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
    } while (next_permutation(arr, arr + n));
}