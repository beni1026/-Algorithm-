#include <iostream>
#include <algorithm> 
#include <string>
#include <cmath>
using namespace std;

bool chk(string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

string num;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    while (true) {
        cin >> num;
        if (num == "0") break;
        int len = num.length();
        int cnt = 0;
        while (!chk(num)) {
            cnt++;
            int num_i = stoi(num);
            num_i++;
            num = to_string(num_i);
            while (num.length() < len) {
                num = "0" + num;
            }
        }
        cout << cnt << "\n";
        
    }
}
