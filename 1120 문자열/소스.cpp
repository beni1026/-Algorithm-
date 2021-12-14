#include <iostream>
#include <algorithm> 
using namespace std;

int n, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    while (1) {
        if (n == 0) break;
        if (n % 5 == 0) {
            ans += n / 5;
            break;
        }
        if (n < 3) {
            ans = -1;
            break;
        }
        n -= 3;
        ans++;
    }

    
    

    cout << ans;

}
