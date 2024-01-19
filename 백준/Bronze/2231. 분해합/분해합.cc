#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

int main() {

    vector<int> v;

    int n; cin >> n;

    int answer = 0;
    int digit = countDigits(n);


    for (int i = 1; i <= n; i++) {
        int temp = i;
        int sum = 0;
        for (int j = 0; j < digit; j++) {
            sum += temp % 10;
            temp /= 10;
        }
        if (n == i + sum) {
            answer = i;
            break;
        }
    
            
    }

    cout << answer;

   


    return 0;
}