#include<iostream>
using namespace std;
long long gcd(int a, int b);
long long lcm(int a, int b);


int main() {
    int a = 0, b = 0;
    cin >> a;
    cin >> b;
    cout << lcm(a, b);
}

long long gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, (a % b));
}

long long lcm(int a, int b) {
    long long result = (gcd(a, b));
    return (a/result) * b;
}