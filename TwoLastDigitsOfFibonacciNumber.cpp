#include<iostream>
#include<vector>
#include<string>
using namespace std;

int get_fibonacci_last_digit(int number);
int get_mod(long long number);

int main() {
    int number = 0;
    cin >> number;
    cout << get_fibonacci_last_digit(number);
}

int get_mod(long long number) {
    return (number % 10);
}

int get_fibonacci_last_digit(int number) {
    
    vector<int> numbers(number+1);
    numbers[0] = 0;
    numbers[1] = 1;

    for (int i = 2; i < numbers.size(); i++) {
        numbers[i] = get_mod(numbers[i-1] + numbers[i-2]);
    }

    return numbers[number];
}
