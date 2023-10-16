#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    queue<pair<int,int>> q;
    
    for(int i = 0; i < prices.size(); i++){
        int value = 0;
        for(int j = i; j < prices.size(); j++){
           if(prices[i] < prices[j]){
               value++;
           }
        }
        answer.push_back(value);
    }
    return answer;
}
