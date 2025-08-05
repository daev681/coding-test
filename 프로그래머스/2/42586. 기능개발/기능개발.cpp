#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;

    // 각 작업마다 완료까지 걸리는 일 수 계산
    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = ceil((double)remain / speeds[i]);
        days.push_back(day);
    }

    stack<int> s;
    int current = days[0];
    s.push(current);

    for (int i = 1; i < days.size(); i++) {
        if (days[i] <= current) {
            // 함께 배포 가능
            s.push(days[i]);
        } else {
            // 배포 완료
            answer.push_back(s.size());
            while (!s.empty()) s.pop();

            current = days[i];
            s.push(current);
        }
    }

    // 마지막 그룹 처리
    if (!s.empty()) {
        answer.push_back(s.size());
    }

    return answer;
}