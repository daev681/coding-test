#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.size();

    // 각 문자에 대한 상하 이동 횟수 계산
    for (char ch : name) {
        int up = ch - 'A';
        int down = 'Z' - ch + 1;
        answer += min(up, down);
    }

    // 좌우 이동 횟수 계산
    int cursorMove = length - 1;
    for (int i = 0; i < length; ++i) {
        if (name[i] != 'A') {
            int nextNonA = i + 1;
            while (nextNonA < length && name[nextNonA] == 'A') {
                ++nextNonA;
            }

            // 기존의 방식으로 계산
            int distance = min(i, length - nextNonA);

            // 새로운 방식으로 계산
            int newDistance = i + length - nextNonA;

            // 더 작은 값으로 업데이트
            cursorMove = min(cursorMove, max(distance, newDistance));
        }
    }

    // 상하 이동과 좌우 이동 횟수를 합하여 최종 답 계산
    answer += cursorMove;

    return answer;
}


