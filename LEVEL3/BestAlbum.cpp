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
#include <utility>
#include <algorithm> // Include the algorithm header for sort

using namespace std;

// 사용자 정의 비교 함수
bool compareSongs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    map<string, pair<int, int>> total_map; // 전체 토탈 맵
    map<string, int> play_map; // 플레이 맵
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++){
        auto it = play_map.find(genres[i]);
        play_map[genres[i]] += plays[i];
    }

    // 플레이 횟수 순으로 장르를 정렬
    vector<pair<string, int>> genre_play_count(play_map.begin(), play_map.end());
    sort(genre_play_count.begin(), genre_play_count.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    for (const auto& genre_count_pair : genre_play_count) {
        const string& genre = genre_count_pair.first;
        // 해당 장르의 노래를 플레이 횟수가 높은 순으로 최대 2개까지 answer에 추가
        vector<pair<int, int>> song_info; // <플레이 횟수, 노래 인덱스> 정보 저장
        for (int i = 0; i < genres.size(); i++) {
            if (genres[i] == genre) {
                song_info.push_back({plays[i], i});
            }
        }

        // 사용자 정의 비교 함수를 사용하여 노래를 정렬
        sort(song_info.begin(), song_info.end(), compareSongs);

        for (int i = 0; i < min(2, (int)song_info.size()); i++) {
            answer.push_back(song_info[i].second);
        }
    }
    
    return answer;
}
