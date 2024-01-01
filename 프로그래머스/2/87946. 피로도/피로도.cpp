#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
     int answer = 0;
    int row_size = dungeons.size();

    std::vector<int> row_indices(row_size);
    for (int i = 0; i < row_size; ++i) {
        row_indices[i] = i;
    }

    do {
        int current_fatigue = k;
        int explored_dungeons = 0;

        for (int i = 0; i < row_size; ++i) {
            int dungeon_index = row_indices[i];
            int required_fatigue = dungeons[dungeon_index][0];

            if (required_fatigue > current_fatigue) {
                break;
            }

            current_fatigue -= dungeons[dungeon_index][1];
            ++explored_dungeons;
        }

        answer = std::max(answer, explored_dungeons);

    } while (std::next_permutation(row_indices.begin(), row_indices.end()));

    return answer;
}