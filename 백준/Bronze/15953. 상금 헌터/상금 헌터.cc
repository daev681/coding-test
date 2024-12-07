
/*
카카오 코드 페스티벌에서 빠질 수 없는 것은 바로 상금이다. 2017년에 개최된 제1회 코드 페스티벌에서는, 본선 진출자 100명 중 21명에게 아래와 같은 기준으로 상금을 부여하였다.

순위	상금	인원
1등	500만원	1명
2등	300만원	2명
3등	200만원	3명
4등	50만원	4명
5등	30만원	5명
6등	10만원	6명
2018년에 개최될 제2회 코드 페스티벌에서는 상금의 규모가 확대되어, 본선 진출자 64명 중 31명에게 아래와 같은 기준으로 상금을 부여할 예정이다.

순위	상금	인원
1등	512만원	1명
2등	256만원	2명
3등	128만원	4명
4등	64만원	8명
5등	32만원	16명
*/


// 출력
// 각 가정이 성립할 때 제이지가 받을 상금을 원 단위의 정수로 한 줄에 하나씩 출력한다. 입력이 들어오는 순서대로 출력해야 한다.

// 예제 입력 1 
// 6
// 8 4
// 13 19
// 8 10
// 18 18
// 8 25
// 13 16
// 예제 출력 1 
// 1780000
// 620000
// 1140000
// 420000
// 820000
// 620000


#include <iostream>
#include <vector>
#include <algorithm> // std::max_element
#include <utility>

int main() {

   int n;
   std::vector<std::pair<int, int>> sv = {
        {5000000, 1},
        {3000000, 2},
        {2000000, 3},
        {500000, 4},
        {300000, 5},
        {100000, 6},
   };
   
   std::vector<std::pair<int, int>> ev = {
        {5120000, 1},
        {2560000, 2},
        {1280000, 4},
        {640000, 8},
        {320000, 16},
   };



   std::cin >> n;
   std::vector<std::pair<int , int>> v;
    
     
   
   for (int i = 0; i < n; i++)
   {  
    
      int sv_total = 0;
      int ev_total = 0;
      int answer = 0;
       int a, b;
       std::cin >> a;
       std::cin >> b;
        for (const auto& prize : sv){
            sv_total += prize.second;
            if(sv_total >= a && a != 0){
                answer += prize.first;
                break;
            }
        }
            for (const auto& prize : ev){
            ev_total += prize.second;
            if(ev_total >= b && b != 0){
                answer += prize.first;
                break;
            }
        }
        
    std::cout << answer << std::endl;
   }

  

    return 0;

 }