#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
long long maxPairwiseProduct(vector<int>);
long long maxPairwiseProductFast(vector<int>);

int main() {
    while(true) {
        int total = rand() % 1000 + 2;
        cout << total;

        vector<int> numbers(total);
    
        for (int i = 0; i < total; i++) {
            numbers[i] = rand() % 100000;
        }

        for (int i = 0; i < total; i++) {
            cout << numbers[i] << " ";
        }

        long long res1 = maxPairwiseProduct(numbers);
        long long res2 = maxPairwiseProductFast(numbers);

        if (res1 != res2) {
            cout << "wrong answer: "
                << res1
                << " "
                << res2
                << "\n";
            break;
        } else {
            cout << "OK\n";
        }
    }

    return 0;
}

long long maxPairwiseProduct(vector<int> lista) {

    long long max  = 0;
    long long max2 = 0;
    long long result;

    for (int i=0; i < lista.size(); i++) {
        if (lista[i] >= max) {
            max2 = max;
            max = lista[i];
        } else {
            if (lista[i] > max2) {
                max2 = lista[i];
            }
        }
    }

    result = (long long) max * max2;

    return result;
}

long long maxPairwiseProductFast(vector<int> lista) {

    long long max  = 0;
    long long max2 = 0;
    long long result;

    for (int i=0; i < lista.size(); i++) {
        if (lista[i] >= max) {
            max2 = max;
            max = lista[i];
        } else {
            if (lista[i] > max2) {
                max2 = lista[i];
            }
        }
    }

    result = (long long) max * max2;

    return result;
}