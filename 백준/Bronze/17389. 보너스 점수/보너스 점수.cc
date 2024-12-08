
#include <iostream>
#include <string>
int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    int sum = 0;
    int bouns = 0;
    for(int i = 0; i < n; i++){
        char c;
        std::cin >> c;
        if(c == 'O'){
            bouns ++;
            sum += i + bouns;
        }else{
            bouns = 0;
        }
    }
    std::cout << sum;
    return 0;

}