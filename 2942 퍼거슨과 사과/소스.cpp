#include <iostream>
#include <algorithm> 
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

//유클리드 호제법이용 왜냐면 r,g가 10억이 넘으므로 완전탐색하면 1초 넘기때문
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    int r, g, num;
    cin >> r >> g;

    if (r > g) num = gcd(r, g);
    else num = gcd(g, r);

    for (int i = 1; i <= num; i++) {
        if (r % i == 0 && g % i == 0) {
            cout << i << " " << r / i << " " << g / i << endl;
        }
    }
}
