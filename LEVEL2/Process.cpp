//1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
//2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
//3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
//3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.


//priorities	location	return
//[2, 1, 3, 2]	2	1
//[1, 1, 9, 1, 1, 1]	0	5


#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {

    int sign = 0;
    int answer = 0;
    int location_value = priorities[location];
    int size = priorities.size();
    queue<int> q;
    stack<int> s;

    for (int i = 0; i < priorities.size(); i++) {
        if (location != i) {
            q.push(priorities[i]);
        }
    }

    while (!q.empty()) {
        int old_value = q.front();
        if (old_value < location_value) {
            size--;       // 큐에서 맨 앞 요소 제거
            sign = 0;
        }
        else {
            sign = 1;
        }
        q.pop();
        if (sign == 1) {
            int new_value = q.front();
            if (old_value == new_value) {
                size--;

            }
        }


    }

    return size;

}