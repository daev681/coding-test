//스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
//
//속한 노래가 많이 재생된 장르를 먼저 수록합니다.
//장르 내에서 많이 재생된 노래를 먼저 수록합니다.
//장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
//노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.
//
//
//제한사항
//genres[i]는 고유번호가 i인 노래의 장르입니다.
//plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
//genres와 plays의 길이는 같으며, 이는 1 이상 10, 000 이하입니다.
//장르 종류는 100개 미만입니다.
//장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
//모든 장르는 재생된 횟수가 다릅니다.
//입출력 예
//genres	plays	return
//["classic", "pop", "classic", "classic", "pop"][500, 600, 150, 800, 2500][4, 1, 3, 0]
//
//

#include <string>
#include <vector>
#include <map>
#include <utility> // std::make_pair 함수를 사용하기 위한 헤더
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {

    map<string, pair<int, int>> total_map; // 전체 토탈 맵
    map<string, int> play_map; // 플레이 맵


    for (int i = 0; i < genres.size(); i++) {
        auto it = play_map.find(genres[i]);
        play_map[genres[i]] = plays[i];
        if (it != play_map.end()) { // 중복
            int genres_count = total_map[genres[i]].first;
            int plays_sum = total_map[genres[i]].second;
            genres_count++;
            plays_sum += plays[i];
            auto delete_key = total_map.find(genres[i]); // 삭제할 키
            total_map.erase(delete_key); // 키를 삭제 
            total_map[genres[i]] = make_pair(genres_count, plays_sum);
        }
        else { // 중복아님
            total_map[genres[i]] = make_pair(1, plays[i]);
        }
    }

    for (const auto& pair : total_map) {
        const std::string& key = pair.first;
        const std::pair<int, int>& values = pair.second;
        int firstValue = values.first;
        int secondValue = values.second;

        //  std::cout << "키: " << key << ", 값1: " << firstValue << ", 값2: " << secondValue << std::endl;
    }
    for (int i = 0; i < genres.size(); i++) {

        auto it = total_map.find(genres[i]);
        if (it != total_map.end()) {
            answer[i] = i;
        }
        else {

        }



    }

    for (const auto& pair : play_map) {
        std::cout << "키: " << pair.first << ", 값: " << pair.second << std::endl;
    }

    vector<int> answer;
    return answer;
}