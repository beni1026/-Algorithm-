#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
using namespace std;

bool compare(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    else {
        return (a.length() < b.length());
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }
}
