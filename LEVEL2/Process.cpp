//1. ���� ��� ť(Queue)���� ������� ���μ��� �ϳ��� �����ϴ�.
//2. ť�� ������� ���μ��� �� �켱������ �� ���� ���μ����� �ִٸ� ��� ���� ���μ����� �ٽ� ť�� �ֽ��ϴ�.
//3. ���� �׷� ���μ����� ���ٸ� ��� ���� ���μ����� �����մϴ�.
//3.1 �� �� ������ ���μ����� �ٽ� ť�� ���� �ʰ� �״�� ����˴ϴ�.


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
            size--;       // ť���� �� �� ��� ����
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