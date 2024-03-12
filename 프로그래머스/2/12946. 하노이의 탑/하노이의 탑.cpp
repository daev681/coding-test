#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int go, int to, vector<vector<int>>& answer) {
    if(n == 1){
        answer.push_back({go,to});
        return;
    }
    
    int B = 6 - go - to;
    hanoi(n-1, go , B , answer);
    hanoi(1, go , to , answer);
    hanoi(n-1, B , to , answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);
    return answer;
}
