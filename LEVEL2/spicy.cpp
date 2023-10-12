#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int> , greater<int>> q;
    for(int i = 0; i < scoville.size(); i++){
        q.push(scoville[i]);
    }
 
    int mix_data = 0;
    if(q.top() > K){
        return -1;
    }
    while(!q.empty()){ 
        int old_data = q.top();
        q.pop();
        if(old_data >= K){
            return answer;
        }else if (q.size() == 0){
            return -1;       
        }
        int new_data = q.top();
        q.pop();
        mix_data = (old_data + (new_data * 2));
        q.push(mix_data);
        answer++;
    }
        return -1;
}
