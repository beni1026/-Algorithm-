#include <iostream>
#include <algorithm> 
using namespace std;

int n, arr1[100001];
int m;

int binary_search(int arr[], int num) {
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;
    while (true) {
        if (left > right) return 0;
        if (arr[mid] == num) {
            return 1;
        }
        if (arr[mid] > num) {
            right = mid-1;
            mid = (left + right) / 2;
        }
        else {
            left = mid+1;
            mid = (left + right) / 2;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    sort(arr1, arr1 + n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        cout << binary_search(arr1, k) << "\n";
    }
}
