#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    string num;
    
    while (true) {
        cin >> num;
        if (num == "0") break;
        int len = num.length();
        bool chk = true;
        for (int i = 0; i < len / 2; i++) {
            if (num[i] != num[len - i - 1]) chk = false;
        }
        if (chk == true) cout << "yes\n";
        else cout << "no\n";
        
        
    }
}
