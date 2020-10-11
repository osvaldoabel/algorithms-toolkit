#include <iostream>
#include <vector>
 
using namespace std;
long long maxPairwiseProduct(vector<int>);

int main() {
    int total;
    cin >> total;
    vector<int> numbers(total);
    
    for (int i = 0; i < total; i++) {
        std::cin >> numbers[i];
    }

    std::cout << maxPairwiseProduct(numbers);
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