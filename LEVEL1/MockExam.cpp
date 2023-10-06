#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 각 수험생의 패턴을 저장
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    // 패턴 벡터의 크기를 answers 벡터와 맞추기 위해 패턴을 반복
    while (one.size() < answers.size()) {
        one.insert(one.end(), one.begin(), one.end());
    }
    while (two.size() < answers.size()) {
        two.insert(two.end(), two.begin(), two.end());
    }
    while (three.size() < answers.size()) {
        three.insert(three.end(), three.begin(), three.end());
    }

    // 각 수험생의 정답 개수를 계산
    int one_count = 0;
    int two_count = 0;
    int three_count = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i]) {
            one_count++;
        }
        if (answers[i] == two[i]) {
            two_count++;
        }
        if (answers[i] == three[i]) {
            three_count++;
        }
    }

    // 가장 많은 정답 개수를 찾음
    int max_count = max(one_count, max(two_count, three_count));

    // 가장 많은 정답 개수를 가진 수험생을 결과에 추가
    if (one_count == max_count) {
        answer.push_back(1);
    }
    if (two_count == max_count) {
        answer.push_back(2);
    }
    if (three_count == max_count) {
        answer.push_back(3);
    }

    return answer;
}
