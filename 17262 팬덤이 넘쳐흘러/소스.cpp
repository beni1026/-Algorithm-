#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    int n;
    cin >> n;
    int minn = 100001;
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        maxn = max(s, maxn);
        minn = min(e, minn);
    }

    int m = maxn - minn;
    if (m < 0) cout << "0";
    else cout << m;
    
   

}
