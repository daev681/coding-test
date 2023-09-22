#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<std::string, int> counts;

    // 각 의상 종류별로 의상의 개수를 센다.
    for (const auto& item : clothes) {
        string type = item[1]; // 의상 종류
        counts[type]++;
    }

    int result = 1;
    // 각 의상 종류별로 (의상의 개수 + 1)을 곱한다.
    for (const auto& pair : counts) {
        result *= (pair.second + 1);
    }

    // 모든 의상을 입지 않은 경우는 제외한다.
    return result - 1;

}

// https://school.programmers.co.kr/learn/courses/30/lessons/42578#
