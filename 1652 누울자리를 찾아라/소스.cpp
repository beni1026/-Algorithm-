#include <iostream>
#include <algorithm> 
using namespace std;

int n, ans1, ans2;
string s;
char arr[102][102];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < n; j++){
            arr[i][j] = s[j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            bool isX = 0;
            if (arr[i][j] == '.' && arr[i][j + 1] == '.') {
                ans1++;
                for (int k = j+2; k < n-2; k++) {
                    if (arr[i][k] == 'X') {
                        isX = 1;
                        j = k;
                        break;
                    }
                }
                if (isX == 0) break;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n-1; i++) {
            bool isX = 0;
            if (arr[i][j] == '.' && arr[i + 1][j] == '.') {
                ans2++; // ¼¼·Î       
                for (int k = i + 2; k < n-2; k++) {
                    if (arr[k][j] == 'X') {
                        isX = 1;
                        i = k;
                        break;
                    }
                }
                if (isX == 0) break;
            }
        }
    }

    cout << ans1 << " " << ans2;


    
}
