#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> numbers;
    int citaions_size = citations.size();
    sort(citations.rbegin(), citations.rend());
    for (int i = 1; i <= citaions_size; i++) {
        numbers.push_back(i);
    }
    for (int i = 0; i < citaions_size; i++) {
        if (citations[i] < numbers[i]) {
            answer = i;
            break;
        }
        if (i == citaions_size - 1) {
            answer = citaions_size;
        }
    }
    return answer;

}