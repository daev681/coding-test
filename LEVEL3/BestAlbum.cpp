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
    vector<int> answer;
    //�� �帣���� Ƚ������
    map<string, int> music;
    //�� �帣���� �����뷡�� ����� ��������
    map<string, map<int, int>> musiclist;
    //���� ����Ʈ��ŭ �ݺ�
    for (int i = 0; i < genres.size(); i++) {
        //music map�� �帣���� Ƚ���߰�
        music[genres[i]] += plays[i];
        //musiclist map�� �뷡��ȣ�� �÷���Ƚ�� �߰�
        musiclist[genres[i]][i] = plays[i];
    }

    //�帣�� �پ����������� �ݺ�
    while (music.size() > 0) {
        string genre{};
        int max{ 0 };
        //�帣�߿��� ���ϳ����� ã��
        for (auto mu : music) {
            if (max < mu.second) {
                max = mu.second;
                genre = mu.first;
            }
        }
        //2���� �־���ϹǷ� 2���ݺ�
        for (int i = 0; i < 2; i++) {
            int val = 0, ind = -1;
            //�뷡�߿��� ���ϳ����� ã��
            for (auto ml : musiclist[genre]) {
                if (val < ml.second) {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            //���� �뷡�� 0~1��ۿ����ٸ� �ݺ��� Ż��
            if (ind == -1)    break;
            //������ ����Ʈ�� �뷡��ȣ �߰�
            answer.push_back(ind);
            musiclist[genre].erase(ind);
        }
        //map ���� ����� �帣����
        music.erase(genre);
    }
    return answer;
}
