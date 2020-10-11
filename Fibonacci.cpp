#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int number);

int main() {
    int number, result;
    cin >> number;
    cout << fibonacci(number);

    return 0;
}

int fibonacci(int number) {
    vector<int> numbers(number+1);

    int lastPos = 0;
    numbers[0]  = 0;
    numbers[1]  = 1;

    for (int i=2; i<=number; i++) {
        numbers[i] = numbers[i-1] + numbers[i-2];
    }

    lastPos = numbers.size() - 1;
    return numbers[lastPos];
}