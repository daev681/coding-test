#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int& a, const int& b) {
    string strA = to_string(a);
    string strB = to_string(b);
    return strA + strB > strB + strA;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> sort_v;

    sort(numbers.begin(), numbers.end(), compare);

    if (numbers[0] == 0) {
        return "0"; // 모든 수가 0인 경우 "0"을 반환
    }

    for (int i = 0; i < numbers.size(); i++) {
        sort_v.push_back(numbers[i]);
        answer += to_string(numbers[i]);
    }

    return answer;
}
