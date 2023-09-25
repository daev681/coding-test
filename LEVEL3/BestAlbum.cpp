//��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�.�뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.
//
//���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
//�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
//�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
//�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
//
//
//���ѻ���
//genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
//plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
//genres�� plays�� ���̴� ������, �̴� 1 �̻� 10, 000 �����Դϴ�.
//�帣 ������ 100�� �̸��Դϴ�.
//�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
//��� �帣�� ����� Ƚ���� �ٸ��ϴ�.
//����� ��
//genres	plays	return
//["classic", "pop", "classic", "classic", "pop"][500, 600, 150, 800, 2500][4, 1, 3, 0]
//
//

#include <string>
#include <vector>
#include <map>
#include <utility> // std::make_pair �Լ��� ����ϱ� ���� ���
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {

    map<string, pair<int, int>> total_map; // ��ü ��Ż ��
    map<string, int> play_map; // �÷��� ��


    for (int i = 0; i < genres.size(); i++) {
        auto it = play_map.find(genres[i]);
        play_map[genres[i]] = plays[i];
        if (it != play_map.end()) { // �ߺ�
            int genres_count = total_map[genres[i]].first;
            int plays_sum = total_map[genres[i]].second;
            genres_count++;
            plays_sum += plays[i];
            auto delete_key = total_map.find(genres[i]); // ������ Ű
            total_map.erase(delete_key); // Ű�� ���� 
            total_map[genres[i]] = make_pair(genres_count, plays_sum);
        }
        else { // �ߺ��ƴ�
            total_map[genres[i]] = make_pair(1, plays[i]);
        }
    }

    for (const auto& pair : total_map) {
        const std::string& key = pair.first;
        const std::pair<int, int>& values = pair.second;
        int firstValue = values.first;
        int secondValue = values.second;

        //  std::cout << "Ű: " << key << ", ��1: " << firstValue << ", ��2: " << secondValue << std::endl;
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
        std::cout << "Ű: " << pair.first << ", ��: " << pair.second << std::endl;
    }

    vector<int> answer;
    return answer;
}