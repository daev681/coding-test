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

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {

    map<string, pair<int, int>> totalMap; // ��ü ��Ż ��
    map<string, int> playMap; // �÷��� ��

    for (int i = 0; i < genres.size(); i++) {
        playMap[genres[i]] = plays[i];
    }

    totalMap[genres[i]] = make_pair(plays[i], "Alice");


    vector<int> answer;
    return answer;
}