#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >>  s2;
    int cnt = 0;
    int mincnt = 1e9;
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        cout << cnt;
    }
    else {
        int j = 0;
        int sub = s2.length() - s1.length();
        while (j <= sub) {
            cnt = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i+j]) cnt++;
            }
            mincnt = min(cnt, mincnt);
            j++;
        }
        cout << mincnt;
    }

    


}
