#include <iostream> 
#include <string> 
using namespace std;



int factorial(int n) {

    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main(void) {
    int a;
    cin >> a;

    long long value = 1;
    for (int i = 1; i <= a; i++) {
        value *= i;
    }

    cout << value << endl;

    return 0;
}