/*
수빈이와 수열 다국어
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	32 MB	5861	4246	3797	75.069%
문제
수빈이는 심심해서 수열을 가지고 놀고 있다. 먼저, 정수 수열 A를 쓴다. 그리고 그 아래에 정수 수열 A의 해당 항까지의 평균값을 그 항으로 하는 정수 수열 B를 쓴다.

예를 들어, 수열 A가 1, 3, 2, 6, 8이라면, 수열 B는 1/1, (1+3)/2, (1+3+2)/3, (1+3+2+6)/4, (1+3+2+6+8)/5, 즉, 1, 2, 2, 3, 4가 된다.

수열 B가 주어질 때, 수빈이의 규칙에 따른 수열 A는 뭘까?

입력
첫째 줄에는 수열 B의 길이만큼 정수 N(1 ≤ N ≤ 100)이 주어지고, 둘째 줄에는 수열 Bi를 이루는 N개의 정수가 주어진다. (1 ≤ Bi ≤ 109)

출력
첫째 줄에는 수열 A를 이루는 N개의 정수를 출력한다. (1 ≤ Ai ≤ 109)

예제 입력 1
1
2
예제 출력 1
2

예제 입력 2
4
3 2 3 5
예제 출력 2
3 1 5 11

예제 입력 3
5
1 2 2 3 4
예제 출력 3
1 3 2 6 8
 */

// a[0] = b[0] * i
// a[1] = b[1] * i - a[0]
// a[2] = b[2] * i - a[0] - a[1]

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::vector<int> b;
    std::vector<int> answer;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int input;
        std::cin >> input;
        b.push_back(input);

        if (answer.size() != 0)
        {
            for (const auto &a : answer)
            {
                sum += a;
            }
            answer.push_back((b[i - 1] * i) - sum);
        }
        else
        {
            answer.push_back(b[i - 1] * i);
        }
    }

    for (const auto &elem : answer)
    {
        std::cout << elem << " "; // 각 원소를 출력하고 뒤에 쉼표 추가
    }

    return 0;
}