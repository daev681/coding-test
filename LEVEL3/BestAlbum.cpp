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
    vector<int> answer;
    //각 장르별로 횟수저장
    map<string, int> music;
    //각 장르별로 무슨노래가 몇번씩 저장됬는지
    map<string, map<int, int>> musiclist;
    //들어온 리스트만큼 반복
    for (int i = 0; i < genres.size(); i++) {
        //music map에 장르별로 횟수추가
        music[genres[i]] += plays[i];
        //musiclist map에 노래번호와 플레이횟수 추가
        musiclist[genres[i]][i] = plays[i];
    }

    //장르가 다없어질때까지 반복
    while (music.size() > 0) {
        string genre{};
        int max{ 0 };
        //장르중에서 제일높은것 찾기
        for (auto mu : music) {
            if (max < mu.second) {
                max = mu.second;
                genre = mu.first;
            }
        }
        //2곡을 넣어야하므로 2번반복
        for (int i = 0; i < 2; i++) {
            int val = 0, ind = -1;
            //노래중에서 제일높은것 찾기
            for (auto ml : musiclist[genre]) {
                if (val < ml.second) {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            //만약 노래가 0~1곡밖에없다면 반복문 탈출
            if (ind == -1)    break;
            //리턴할 리스트에 노래번호 추가
            answer.push_back(ind);
            musiclist[genre].erase(ind);
        }
        //map 에서 사용한 장르삭제
        music.erase(genre);
    }
    return answer;
}
