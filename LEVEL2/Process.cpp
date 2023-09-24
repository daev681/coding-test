//1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
//2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
//3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
//3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.


//priorities	location	return
//[2, 1, 3, 2]	2	1
//[1, 1, 9, 1, 1, 1]	0	5

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // pair의 첫 번째 요소는 우선순위, 두 번째 요소는 인덱스

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
    }

    while (!q.empty()) {
        int current_priority = q.front().first;
        int current_index = q.front().second;
        q.pop();

        bool can_print = true;

        // 현재 문서보다 우선순위가 높은 문서가 있는지 확인
        for (auto item : q) {
            if (item.first > current_priority) {
                can_print = false;
                break;
            }
        }

        if (can_print) {
            answer++;
            if (current_index == location) {
                break; // 주어진 위치의 문서가 출력되었으므로 종료
            }
        }
        else {
            q.push({ current_priority, current_index }); // 현재 문서를 다시 큐에 넣음
        }
    }

    return answer;
}

