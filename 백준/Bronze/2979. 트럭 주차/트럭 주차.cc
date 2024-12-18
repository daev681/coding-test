/*
트럭 주차 다국어
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	12872	8742	6760	67.512%
문제
상근이는 트럭을 총 세 대 가지고 있다. 오늘은 트럭을 주차하는데 비용이 얼마나 필요한지 알아보려고 한다.

상근이가 이용하는 주차장은 주차하는 트럭의 수에 따라서 주차 요금을 할인해 준다.

트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 두 대를 주차할 때는 1분에 한 대당 B원, 세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.

A, B, C가 주어지고, 상근이의 트럭이 주차장에 주차된 시간이 주어졌을 때, 주차 요금으로 얼마를 내야 하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문제에서 설명한 주차 요금 A, B, C가 주어진다. (1 ≤ C ≤ B ≤ A ≤ 100)

다음 세 개 줄에는 두 정수가 주어진다. 이 정수는 상근이가 가지고 있는 트럭이 주차장에 도착한 시간과 주차장에서 떠난 시간이다. 도착한 시간은 항상 떠난 시간보다 앞선다. 입력으로 주어지는 시간은 1과 100사이 이다.

출력
첫째 줄에 상근이가 내야하는 주차 요금을 출력한다.

예제 입력 1 
5 3 1
1 6 
3 5 
2 8 
예제 출력 1 
33
예제 입력 2 
10 8 6
15 30
25 50
70 80
예제 출력 2 
480
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> sv(3), ev(3);
    for (int i = 0; i < 3; i++) {
        cin >> sv[i] >> ev[i];
    }

    int total_fee = 0;

 
    int start_time = *min_element(sv.begin(), sv.end());
    int end_time = *max_element(ev.begin(), ev.end());

    for (int t = start_time; t < end_time; t++) {
        int count = 0;

        for (int i = 0; i < 3; i++) {
            if (sv[i] <= t && t < ev[i]) {
                count++;
            }
        }

     
        if (count == 1) {
            total_fee += A;
        } else if (count == 2) {
            total_fee += B * 2;
        } else if (count == 3) {
            total_fee += C * 3;
        }
    }

    cout << total_fee << endl;

    return 0;
}
