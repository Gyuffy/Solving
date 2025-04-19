#include <iostream>
using namespace std;

// 최대공약수 함수
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int A, B;
    cin >> A >> B;

    int num = B - A;
    int denom = B;

    int g = gcd(num, denom);

    // 기약분수로 출력
    cout << num / g << " " << denom / g << endl;

    return 0;
}
