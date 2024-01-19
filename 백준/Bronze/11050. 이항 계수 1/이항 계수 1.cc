#include <iostream>

using namespace std;


int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int binomialCoefficient(int n, int k) {
    if (k < 0 || k > n) {
        return 0; 
    }

    // 이항 계수 공식: nCk = n! / (k! * (n-k)!)
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int result = binomialCoefficient(n, k);

    cout << result << endl;

    return 0;
}