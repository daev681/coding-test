#include <string>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int DFS(vector<int> numbers, int target, int index, int sum, int length) {
    if (index == length) { // 모든 원소를 처리한 경우
        if (sum == target) {
            return 1; // 타겟을 만족하면 1 반환
        } else {
            return 0; // 타겟을 만족하지 않으면 0 반환
        }
    }

    // 현재 원소를 양수로 더하고 음수로 더한 경우를 모두 탐색
    int positiveCase = DFS(numbers, target, index + 1, sum + numbers[index], length);
    int negativeCase = DFS(numbers, target, index + 1, sum - numbers[index], length);

    return positiveCase + negativeCase; // 가능한 모든 경우의 합 반환
}

int DFS_stack(vector<int> numbers, int target) {
    int answer = 0;
    stack<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int current_index = q.top().first;
        int current_sum = q.top().second;
        q.pop();

        if (current_index == numbers.size()) { // 모든 숫자를 처리한 경우
            if (current_sum == target) {
                answer++;
            }
        } else {
            // 다음 원소를 양수로 더하고 음수로 더한 경우를 큐에 추가
            q.push({current_index + 1, current_sum + numbers[current_index]});
            q.push({current_index + 1, current_sum - numbers[current_index]});
        }
    }

    return answer;
}


int BFS(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int current_index = q.front().first;
        int current_sum = q.front().second;
        q.pop();

        if (current_index == numbers.size()) { // 모든 숫자를 처리한 경우
            if (current_sum == target) {
                answer++;
            }
        } else {
            // 다음 원소를 양수로 더하고 음수로 더한 경우를 큐에 추가
            q.push({current_index + 1, current_sum + numbers[current_index]});
            q.push({current_index + 1, current_sum - numbers[current_index]});
        }
    }

    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = DFS(numbers, target, 0, 0, numbers.size());
    return answer;
}

