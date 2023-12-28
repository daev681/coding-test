#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int countPrimesUpTo(int limit) {
    int count = 0;

    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            ++count;
        }
    }

    return count;
}

int solution(string numbers) {
    int answer = 0;
    int inumbers = 0;
    inumbers = stoi(numbers);
    answer = countPrimesUpTo(inumbers);

    return answer;
}