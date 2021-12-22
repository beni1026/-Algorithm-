#include <iostream>
#include <algorithm> 
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

//��Ŭ���� ȣ�����̿� �ֳĸ� r,g�� 10���� �����Ƿ� ����Ž���ϸ� 1�� �ѱ⶧��
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
