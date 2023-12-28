#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
        
    bool answer = true;
    
    unordered_map<string, int> map;
    for (int i = 0; i < phone_book.size(); i++)
        map[phone_book[i]] = 1;

 
    for (int i = 0; i < phone_book.size() ; i++)
    {
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            string phone_number = phone_book[i].substr(0, j + 1);
            cout << phone_book[i] << ":" <<phone_number << ":" << map[phone_number] << endl;
            if (map[phone_number])
                return false;
        }
    }

  
    return true;


    return answer;
    

}
