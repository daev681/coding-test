/*
팰린드롬인지 확인하기
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	96150	58424	49407	60.921%
문제
알파벳 소문자로만 이루어진 단어가 주어진다. 이때, 이 단어가 팰린드롬인지 아닌지 확인하는 프로그램을 작성하시오.

팰린드롬이란 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말한다. 

level, noon은 팰린드롬이고, baekjoon, online, judge는 팰린드롬이 아니다.

입력
첫째 줄에 단어가 주어진다. 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.

출력
첫째 줄에 팰린드롬이면 1, 아니면 0을 출력한다.

예제 입력 1 
level
예제 출력 1 
1

예제 입력 2 
baekjoon
예제 출력 2 
0

출처
문제를 만든 사람: baekjoon
데이터를 추가한 사람: oopar2, pda_pro12
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
    string n;
    cin >> n;

 
    int left = 0;
    int right = n.length() - 1;

    while (left < right) {
        if (n[left] != n[right]) {
            cout << 0;  
            return 0;
        }
        left++;
        right--;
    }
       cout << 1;  // 팰린드롬이면 1 출력
    return 0;
}