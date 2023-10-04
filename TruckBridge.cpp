#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck_waiting;
    queue<int> truck_running;
    queue<int> truck_end;
    
    for(int i = 0; i < truck_weights.size(); i++){
     truck_waiting.push(truck_weights[i]);   
    }
    
    while(!truck_waiting.empty()){
        int wait_front = truck_waiting.front();
        truck_weights.pop();
        // truck_wegiht > weight ㄱㅗㄹㅕ
        int current_length = truck_running.size();
        if(current_lenght < bridge_length){
            if(!truck_running.empty()){
                int run_front = truck_running.pop();
                int total_weight = run_front  + wait_front;
                if(total_weight < weight){
                   truck_running.push(run_front);
                    truck_running.push(wait_front);
                   answer++;
                }else{
                    truck_running.push(run_front);
                    answer++;
                }
            }else{
            truck_running.push(wait_front);
            answer++;
            }   
        }else{
            truck_running.pop();
            answer++;
        }
    }
    
    return answer;
}
