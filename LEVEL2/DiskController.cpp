#include <string>
#include <vector>
#include <queue>
#include <functional>    // greater, less

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    return answer;
     priority_queue<pair<int , int>> pq;
    
     for (int i = 0; i < jobs.size(); i++) { //
        pq.push(make_pair(jobs[i][0], jobs[i][1])); 
    }
    
    
    
}
