#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int arr[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    int n;
    int big = -1e9;
    int small = 1e9;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        big = max(big, arr[i]);
        small = min(small, arr[i]);
    }

    cout << small << " " << big;

}
