#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i = 0; i < prices.size(); i++){
        int value = 0;
        for(int j = i + 1; j < prices.size(); j++){
           if(prices[i] <= prices[j]){
               value++;
           }else {
                value++;
                break; // 현재 가격보다 작아지면 루프 종료
            }
        }
        answer.push_back(value);
    }
    return answer;
}
