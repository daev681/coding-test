#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        int first = commands[i][0];
        int second = commands[i][1];
        int target = commands[i][2];
        vector<int> split_v;
        for(int j = first -1; j <= second-1; j++){
            cout << array[j] << " ";
            split_v.push_back(array[j]);
        }
        cout << endl ;
        sort(split_v.begin(),split_v.end());
        answer.push_back(split_v[target-1]);
    }
    return answer;
}
