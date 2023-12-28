#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#include<algorithm>
#include <functional>         // greater 사용 위해 필요  
#include <vector>
#include<queue>
using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights);

int main() {
    // Test case 1
    int bridge_length1 = 2;
    int weight1 = 10;
    vector<int> truck_weights1 = { 7, 4, 5, 6 };
  //  int result1 = solution(bridge_length1, weight1, truck_weights1);
  //  cout << "Test case 1 result: " << result1 << endl;

    // Test case 2
    int bridge_length2 = 100;
    int weight2 = 100;
    vector<int> truck_weights2 = { 10 };
  //  int result2 = solution(bridge_length2, weight2, truck_weights2);
  //  cout << "Test case 2 result: " << result2 << endl;

    // Test case 3
    int bridge_length3 = 100;
    int weight3 = 100;
    vector<int> truck_weights3 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    int result3 = solution(bridge_length3, weight3, truck_weights3);
    cout << "Test case 3 result: " << result3 << endl;

    return 0;
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> running;
    int i = 0;
    int current_weight = 0;

    while (i < truck_weights.size() || !running.empty()) {
        answer++;

        if (running.size() != 0 && running.size() != bridge_length && wait_front != 0) {
            int check = running_weight + wait_front;
            if (check >= weight) {
                running_weight -= running.front();
                running.pop();
                answer++;
            }
            else {
                running.push(wait_front);
                if (!waiting.empty()) waiting.pop();
                running_weight += wait_front;
                answer++;
            }
        }
        else if (running.size() == 0 && !waiting.empty()) {
            running.push(wait_front);
            if (!waiting.empty()) waiting.pop();
            running_weight += wait_front;
            answer++;
        }

        if (i < truck_weights.size() && current_weight + truck_weights[i] <= weight) {
            current_weight += truck_weights[i];
            running.push(make_pair(truck_weights[i], answer));
            i++;
        }
    }

    return answer;
}
