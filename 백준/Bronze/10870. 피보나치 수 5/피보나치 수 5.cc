#include <iostream> 
#include <string> 
#include <vector>
using namespace std;


vector<int> memo;

long long Fibonacci(int n) {

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return memo[n];
}

int main(void) {
    int a;
    cin >> a;
    memo.resize(a + 1, -1);
    cout << Fibonacci(a) << endl;


    return 0;
}