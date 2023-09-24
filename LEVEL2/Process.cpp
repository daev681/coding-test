//1. ���� ��� ť(Queue)���� ������� ���μ��� �ϳ��� �����ϴ�.
//2. ť�� ������� ���μ��� �� �켱������ �� ���� ���μ����� �ִٸ� ��� ���� ���μ����� �ٽ� ť�� �ֽ��ϴ�.
//3. ���� �׷� ���μ����� ���ٸ� ��� ���� ���μ����� �����մϴ�.
//3.1 �� �� ������ ���μ����� �ٽ� ť�� ���� �ʰ� �״�� ����˴ϴ�.


//priorities	location	return
//[2, 1, 3, 2]	2	1
//[1, 1, 9, 1, 1, 1]	0	5

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // pair�� ù ��° ��Ҵ� �켱����, �� ��° ��Ҵ� �ε���

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
    }

    while (!q.empty()) {
        int current_priority = q.front().first;
        int current_index = q.front().second;
        q.pop();

        bool can_print = true;

        // ���� �������� �켱������ ���� ������ �ִ��� Ȯ��
        for (auto item : q) {
            if (item.first > current_priority) {
                can_print = false;
                break;
            }
        }

        if (can_print) {
            answer++;
            if (current_index == location) {
                break; // �־��� ��ġ�� ������ ��µǾ����Ƿ� ����
            }
        }
        else {
            q.push({ current_priority, current_index }); // ���� ������ �ٽ� ť�� ����
        }
    }

    return answer;
}

