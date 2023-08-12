#include <iostream>
#include <string>
using namespace std;

int n, arr[65][65];
string ans = "";
void division(int sx, int sy, int ex, int ey, int n) {
    int b_cnt = 0, w_cnt = 0;
    if (n == 0) return;

    for (int i = sx; i < ex; i++) {
        for (int j = sy; j < ey; j++) {
            if (arr[i][j] == 0) w_cnt++;
            else b_cnt++;
        }
    }

    if (b_cnt == n * n) {
        ans += "1";
    }
    else if (w_cnt == n * n) {
        ans += "0";
    }
    else {
        ans += "(";
        division(sx, sy, (ex + sx) / 2, (ey + sy) / 2, n / 2);
        division(sx, (ey + sy) / 2, (ex + sx) / 2, ey, n / 2);
        division((sx + ex) / 2, sy, ex, (ey + sy) / 2, n / 2);       
        division((ex + sx) / 2, (ey + sy) / 2, ex, ey, n / 2);
        ans += ")";
    }
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	division(0, 0, n, n, n);

    cout << ans;
	return 0;
}