#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
       int isize = brown + yellow;
    int jsize = brown + yellow;

    vector<int> answer;

    for (int i = 1; i <= isize; i++) {
        for (int j = 1; j <= jsize; j++) {
            if (isize == i * j && i >= j && (i - 2) * (j - 2) == yellow) {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }

    return answer;
}