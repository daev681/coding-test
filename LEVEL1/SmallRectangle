#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int height_max = 0;
    int width_max =0;
    for(int i = 0; i < sizes.size(); i++){
        int width = max(sizes[i][0],sizes[i][1]);
        int height = min(sizes[i][1],sizes[i][0]);
        
        width_max =max(width , width_max);
        height_max =max(height, height_max);
        
    }
    answer = height_max * width_max;
    return answer;
}
