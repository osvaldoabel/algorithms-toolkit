#include<iostream>
using namespace std;
int gcd(int a, int b);


int main() {
    int a = 0, b = 0;
    cin >> a;
    cin >> b;
    cout << gcd(a, b);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, (a % b));
}