#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
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


void generateAllCombinations(const std::string& numberStr, int& answer) {
    std::string tempStr = numberStr;
    std::sort(tempStr.begin(), tempStr.end());
    set<int> s;

    do {
        for (int len = 1; len <= tempStr.size(); ++len) {
            int num = std::stoi(tempStr.substr(0, len));
            cout << num << endl;
            if (isPrime(num)) {
                s.insert(num);
            }
        }
    } while (std::next_permutation(tempStr.begin(), tempStr.end()));
    answer = s.size();
}

int solution(string numbers) {
    int answer = 0;

    generateAllCombinations(numbers, answer);


    return answer;
}