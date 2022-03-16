#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int n;
long arr[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        arr[i] = stol(s);
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
}
