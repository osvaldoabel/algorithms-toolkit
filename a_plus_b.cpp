#include <iostream>

int sum_a_and_b(int a, int b)
{
    return a + b;
}

int main()
{
    int num1, num2, result = 0;

    std::cin >> num1;
    std::cin >> num2;

    result = sum_a_and_b(num1, num2);
    std::cout << result;

    return 0;
}