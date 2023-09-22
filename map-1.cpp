#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<std::string, int> counts;

    // �� �ǻ� �������� �ǻ��� ������ ����.
    for (const auto& item : clothes) {
        string type = item[1]; // �ǻ� ����
        counts[type]++;
    }

    int result = 1;
    // �� �ǻ� �������� (�ǻ��� ���� + 1)�� ���Ѵ�.
    for (const auto& pair : counts) {
        result *= (pair.second + 1);
    }

    // ��� �ǻ��� ���� ���� ���� �����Ѵ�.
    return result - 1;

}

// https://school.programmers.co.kr/learn/courses/30/lessons/42578#
