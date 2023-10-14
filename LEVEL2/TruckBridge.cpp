#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> running;
    int i = 0;
    int current_weight = 0;

    while (i < truck_weights.size() || !running.empty()) {
        answer++;

        if (!running.empty() && answer - running.front().second == bridge_length) {
            current_weight -= running.front().first;
            running.pop();
        }

        if (i < truck_weights.size() && current_weight + truck_weights[i] <= weight) {
            current_weight += truck_weights[i];
            running.push(make_pair(truck_weights[i], answer));
            i++;
        }
    }

    return answer;
}
